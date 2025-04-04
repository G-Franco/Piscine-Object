/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mapper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/04 14:48:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mapper.hpp"
#include "../include/helper.hpp"
#include "../include/Train.hpp"
#include <cmath>
#include <queue>
#include <unordered_map>

Mapper::Mapper(std::unordered_map<std::string,
               std::vector<Rail *>> &network,
               std::vector<Train> &trains)
  : _network(network),
    _trains(trains) {}

Mapper::~Mapper() {}

void Mapper::calculate_routes() {
  for (auto &train : _trains) {
    auto route = find_route(train.get_start(), train.get_end(), train);
    train._timetable = create_timetable(route, train);
  }
}

// Priority queue element
// Without this alias, the code is difficult to read
// 1st - Total time to reach station
// 2nd - Station name
using PQ_element = std::pair<double, std::string>;

// Dijkstra's algorithm
// https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
// Priority queue to access the shortest path first
// https://en.cppreference.com/w/cpp/container/priority_queue
Mapper::route_info Mapper::find_route(const std::string &start,
                                      const std::string &end,
                                      Train &train) {
  // greater<> is used to reverse the priority queue
  // so the shortest path is at the top.
  // Yes, it's counterintuitive, the priority queue comparator evaluates
  // which element has lower priority.
  std::priority_queue<PQ_element, std::vector<PQ_element>, std::greater<PQ_element>> pq;
  // Best time to reach each station
  std::unordered_map<std::string, double> best_times;
  // Tracking previous node and path to reconstruct the route
  std::unordered_map<std::string, previous_info> previous;

  // Start all stations with infinite time
  // The _ means the value is not used
  for (auto &[station, _] : _network) {
    best_times[station] = std::numeric_limits<double>::infinity();
  }
  // Stating station has 0 for time
  best_times[start] = 0.0;
  pq.push(std::make_pair(0.0, start));

  while(!pq.empty()) {
    PQ_element current = pq.top();
    pq.pop();

    if (current.second == end) {
      break;
    }
    // Using >= check instead of a visited set
    // This achieves nearly the same effect as a visited set by skipping
    // any duplicate entries with equal or worse times
    if (current.first >= best_times[current.second]) {
      continue;
    }

    // Explore connections
    for (auto &rail : _network[current.second]) {
      std::string next_station = rail->_node1 == current.second ? rail->_node2 : rail->_node1;

      Path *best_path = nullptr;
      double best_time = std::numeric_limits<double>::infinity();

      for (auto &path : rail->_paths) {
        double time_on_path = calculate_time_on_path(path, train);
        if (time_on_path < best_time) {
          best_time = time_on_path;
          best_path = &path;
        }
      }

      // New time to reach next station
      double time_to_next = current.first + best_time;
      if (time_to_next < best_times[next_station]) {
        best_times[next_station] = time_to_next;
        previous[next_station] = previous_info(current.second, rail, best_path);
        pq.push(std::make_pair(time_to_next, next_station));
      }
    }
  }

  // Reconstruct route
  route_info route;
  route.total_time = best_times[end];

  // If no path found, return empty route
  // This should never happen, keeping it in as a sanity check
  if (route.total_time == std::numeric_limits<double>::infinity()) {
    return route;
  }

  // Going backwards
  std::string current = end;
  route.stations.push_back(current);
  while (current != start) {
    previous_info info = previous[current];
    route.rails.insert(route.rails.begin(), info._rail);
    route.paths.insert(route.paths.begin(), info._path);
    // Move to previous station
    current = info._station;
    route.stations.insert(route.stations.begin(), current);
  }
  return route;
}

Timetable Mapper::create_timetable(Mapper::route_info &route, Train &train) {
  Timetable timetable;
  if (route.total_time == std::numeric_limits<double>::infinity()) {
    return timetable;
  }

  int len = route.stations.size();
  for (int i = 0; i < len - 1; i++) {
    Path *path = route.paths[i];
    double peak_speed = calculate_peak_speed(path->_length, train._acceleration, train._deceleration);
    double max_speed = std::min(std::min(path->_speed_limit, train._max_speed), peak_speed);
    double acceleration_time = train.time_to_change_speed(0, max_speed, train._acceleration);
    double deceleration_time = train.time_to_change_speed(max_speed, 0, train._deceleration);
    double acceleration_distance = train.distance_to_speed(train._acceleration, acceleration_time);
    double deceleration_distance = train.distance_to_speed(train._deceleration, deceleration_time);
    double maintain_speed_distance = path->_length - acceleration_distance - deceleration_distance;
    Section section(
        route.rails[i],
        path,
        route.stations[i],
        route.stations[i + 1],
        Time(-1, -1, -1),
        Time(-1, -1, -1),
        calculate_time_on_path(*path, train),
        acceleration_time,
        maintain_speed_distance / max_speed,
        deceleration_time,
        max_speed);
    
    timetable.add_section(section);
  }
  return timetable;
}

// Optimal case - train can reach max speed and brake to a stop
// without exceeding speed limit
// Path length case - path is too short for the train to reach max speed
// and brake to a stop
// Speed limit case - speed limit is lower than the train's max speed
// The train may still reach max speed and brake to a stop
// OR the track is too short even for that.
// This requires calculating the optimal speed for which a train can
// accelerate and decelerate within the given distance
// without maintaining max speed
// 
// Explanation of the formula:
// a = acceleration
// d = deceleration
// L = distance to effective speed + distance to stop
// speed^2 = initial_speed^2 + 2a * distance
// distance = speed^2 / (2a)
// L = (speed^2 / (2a)) + (speed^2 / (2d))
// L = speed^2 * (1 / (2a) + 1 / (2d))
// L = speed^2 * (a + d) / (2ad)
// speed^2 = L / (a + d) / (2ad)
// speed^2 = L * 2ad / (a + d)
// speed = sqrt(L * 2ad / (a + d))
double Mapper::calculate_time_on_path(Path &path, Train &train) {
  // Early and easy return if the right conditions are met
  // so there is no need to recalculate everything
  double length = path._length;
  if (length >= train._acceleration_deceleration_distance &&
      train._max_speed <= path._speed_limit) {
    // v = d / t => t = d / v
    double max_speed_time = (length - train._acceleration_deceleration_distance) / train._max_speed;
    return train._time_to_max_speed + max_speed_time + train._time_to_stop;
  }
  double acceleration = train._acceleration;
  double deceleration = train._deceleration;
  double peak_speed = calculate_peak_speed(length, acceleration, deceleration);
  double max_speed = std::min(std::min(path._speed_limit, train._max_speed), peak_speed);
  double time_to_max = train.time_to_change_speed(0, max_speed, acceleration);
  double time_to_stop = train.time_to_change_speed(max_speed, 0, deceleration);
  double distance_to_max = train.distance_to_speed(acceleration, time_to_max);
  double distance_to_stop = train.distance_to_speed(deceleration, time_to_stop);
  double time_at_max = (length - distance_to_max - distance_to_stop) / max_speed;
  return time_to_max + time_at_max + time_to_stop;
}

double Mapper::calculate_peak_speed(double length, double acceleration, double deceleration) {
  return std::sqrt(length * 2 * acceleration * deceleration / (acceleration + deceleration));
}
