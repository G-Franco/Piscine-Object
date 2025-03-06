/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_checker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:00:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/06 17:36:39 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../include/File_checker.hpp"
#include "../include/helper.hpp"

File_checker::File_checker(const std::string &rail_file, const std::string &train_file)
  : _rail_file(rail_file),
    _train_file(train_file) {}

File_checker::~File_checker() {}

bool File_checker::validate_files() {
  if (!check_files()) {
    return false;
  }
  if (!validate_nodes() ||
      !validate_rails() ||
      !validate_trains()) {
    return false;
  }
  return true;
}

// Checks for file existence, emptiness and readability
bool File_checker::check_files() {
  bool ret = true;
  if (!_rail_file.is_open()) {
    std::cout << "Error: could not open node file\n";
    ret = false;
  }
  if (!_train_file.is_open()) {
    std::cout << "Error: could not open rail file\n";
    ret = false;
  }

  if (!ret) {
    return ret;
  }
  
  if (_rail_file.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Error: node file is empty\n";
    ret = false;
  }
  if (_train_file.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Error: rail file is empty\n";
    ret = false;
  }

  if (!_rail_file.good()) {
    std::cout << "Error: node file is corrupted or unreadable\n";
    ret = false;
  }
  if (!_train_file.good()) {
    std::cout << "Error: rail file is corrupted or unreadable\n";
    ret = false;
  }
  return ret;
}

// Node line format:
// Node node_name
bool File_checker::validate_nodes() {
  std::string line;
  while (getline(_rail_file, line)) {
    std::string node;
    std::string node_name;
    std::string extra;
    std::istringstream read(line);

    if (!(read >> node >> node_name) ||
        (read >> extra)) {
      std::cout << "Error: invalid Node line format: " << line << "\n";
      return false;
    }
    if (_nodes.find(node_name) != _nodes.end()) {
      std::cout << "Error: node " << node_name << " already exists\n";
      return false;
    }
    _nodes.insert(node_name);
    // Checking if the next line starts with 'N' for Node
    // If not, there should be no more nodes and rails are next
    int next = _rail_file.peek();
    if (next != std::ifstream::traits_type::eof() &&
        next != 'N') {
      return true;
    }
  }
  return true;
}

// Rail line format:
// Rail node1 node2 length speed_limit
bool File_checker::validate_rails() {
  std::string line;
  while (getline(_rail_file, line)) {
    std::string rail;
    std::string node1;
    std::string node2;
    double length;
    double speed_limit;
    std::string extra;
    std::istringstream read(line);

    if (!(read >> rail >> node1 >> node2 >> length >> speed_limit) ||
        rail != "Rail" ||
        (read >> extra)) {
      std::cout << "Error: invalid Rail line format: " << line << "\n";
      return false;
    }
    if (node1 == node2) {
      std::cout << "Error: cannot connect a node to itself: " << line << "\n";
      return false;
    }
    if (_nodes.find(node1) == _nodes.end() ||
        _nodes.find(node2) == _nodes.end()) {
      std::cout << "Error: node not found: " << line << "\n";
      return false;
    }
    if (length <= MIN_RAIL_LENGTH || speed_limit <= MIN_SPEED_LIMIT) {
      std::cout << "Error: invalid length or speed limit: " << line << "\n"
                << "Minimum length: " << MIN_RAIL_LENGTH << "\n"
                << "Minimum speed limit: " << MIN_SPEED_LIMIT << "\n";
      return false;
    }
    if (!add_rail(node1, node2, length, speed_limit)) {
      std::cout << "Error: could not add rail: " << line << "\n";
      return false;
    }
  }
  return true;
}

bool File_checker::add_rail(const std::string &node1, const std::string &node2, double length, double speed_limit) {
  std::string key = node1 > node2 ? node2 + "-" + node1 : node1 + "-" + node2;
  if (_rails.find(key) != _rails.end()) {
    return _rails[key].add_path(length, speed_limit);
  }
  _rails.insert({key, Rail(node1, node2)});
  if (!_rails[key].add_path(length, speed_limit)) {
    _rails.erase(key);
    return false;
  }
  return true;
}

// Train line format:
// TrainXY weight friction_coefficient max_acceleration_force max_break_force
// departure_node arrival_node departure_time station_stop_duration
bool File_checker::validate_trains() {
  std::string line;
  while (getline(_train_file, line)) {
    std::string train;
    double weight;
    double friction_coefficient;
    double max_acceleration_force;
    double max_break_force;
    std::string departure_node;
    std::string arrival_node;
    std::string departure_time;
    std::string station_stop_duration;
    std::string extra;
    std::istringstream read(line);

    if (!(read >> train >> weight >> friction_coefficient
        >> max_acceleration_force >> max_break_force 
        >> departure_node >> arrival_node >> departure_time
        >> station_stop_duration) ||
        (read >> extra)) {
      std::cout << "Error: invalid Train line format: " << line << "\n";
      return false;
    }
    // TODO: Check friction coefficient in later equations to make sure
    // the train won't be immobilized if it's too high
    // TODO: Check normal range of real world values for these parameters
    // to avoid silly situations
    if (weight <= MIN_WEIGHT ||
        friction_coefficient <= 0 ||
        max_acceleration_force <= 0 ||
        max_break_force <= 0 ||
        departure_time < 0 ||
        station_stop_duration < 0) {
      std::cout << "Error: invalid train parameters: " << line << "\n"
                << "Weight, friction coefficient, max acceleration force, max break force, departure time and station stop duration must be positive\n";
      return false;
    }
    if (_nodes.find(departure_node) == _nodes.end() ||
        _nodes.find(arrival_node) == _nodes.end()) {
      std::cout << "Error: node not found: " << line << "\n";
      return false;
    }
  }
  return true;
}
