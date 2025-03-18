/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Central.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:43:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/18 17:41:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Central.hpp"
#include "../include/Train.hpp"
#include "../include/helper.hpp"
#include <cmath>

Central::Central()
  : _network(_network),
    _trains(_trains) {}

Central::~Central() {}

void Central::calculate_paths() {
  for (auto &train : _trains) {
    train_path(train);
  }
}

void Central::train_path(Train &train) {
  
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
double Central::calculate_time_on_path(Path &path, Train &train) {
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
  double peak_speed = std::sqrt(length * 2 * acceleration * deceleration / (acceleration + deceleration));
  double max_speed = std::min(std::min(path._speed_limit, train._max_speed), peak_speed);
  double time_to_max = train.time_to_change_speed(0, max_speed, acceleration);
  double time_to_stop = train.time_to_change_speed(max_speed, 0, deceleration);
  double distance_to_max = train.distance_to_speed(acceleration, time_to_max);
  double distance_to_stop = train.distance_to_speed(deceleration, time_to_stop);
  double time_at_max = (length - distance_to_max - distance_to_stop) / max_speed;
  return time_to_max + time_at_max + time_to_stop;
}
