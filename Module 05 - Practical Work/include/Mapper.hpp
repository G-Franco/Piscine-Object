/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mapper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:07:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/04 14:58:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unordered_map>
#include <vector>
#include <iostream>
#include "Timetable.hpp"

struct Rail;
struct Path;
class Train;

class Mapper {
  private:
    std::unordered_map<std::string, std::vector<Rail *>> &_network;
    std::vector<Train> &_trains;

    // Used to store routes calculated using Dijkstra's algorithm
    struct route_info {
      std::vector<Rail*> rails;
      std::vector<Path*> paths;
      std::vector<std::string> stations;
      double total_time;
    };

    // Used to store the previous node and path
    struct previous_info {
      std::string _station;
      Rail* _rail;
      Path* _path;

      previous_info()
        : _station(""),
          _rail(nullptr),
          _path(nullptr) {}

      previous_info(std::string station, Rail* rail, Path* path)
        : _station(station),
          _rail(rail),
          _path(path) {}
    };

  public:
    Mapper(std::unordered_map<std::string, std::vector<Rail *>> &network,
           std::vector<Train> &trains);
    Mapper(const Mapper &copy) = delete;
    Mapper &operator=(const Mapper &copy) = delete;
    ~Mapper();
    void calculate_routes();
    route_info find_route(const std::string &start, const std::string &end, Train &train);
    Timetable create_timetable(route_info &route, Train &train);
    double calculate_time_on_path(Path &path, Train &train);
    double calculate_peak_speed(double length, double acceleration, double deceleration);
};
