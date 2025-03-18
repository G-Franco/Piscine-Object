/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Railway_factory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:24:26 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/17 17:58:28 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Railway_factory.hpp"
#include "../include/helper.hpp"
#include "../include/Train.hpp"
#include "../include/Time.hpp"
#include <sstream>

void Railway_factory::create_node(const std::string &node_name,
                                  std::vector<std::string> &nodes) {
  if (std::find(nodes.begin(), nodes.end(), node_name) != nodes.end()) {
    throw std::runtime_error("Node already exists");
  }
  nodes.push_back(node_name);
}

void Railway_factory::create_rail(const std::string &node1,
                                  const std::string &node2,
                                  double length, double speed_limit,
                                  std::vector<std::string> &nodes,
                                  std::vector<Rail> &rails) {
  if (node1 == node2) {
    throw std::runtime_error("Node cannot connect to itself");
  }
  if (std::find(nodes.begin(), nodes.end(), node1) == nodes.end() ||
      std::find(nodes.begin(), nodes.end(), node2) == nodes.end()) {
    throw std::runtime_error("Node not found");
  }
  if (length < MIN_RAIL_LENGTH || speed_limit < MIN_SPEED_LIMIT) {
    std::stringstream error;
    error << "Error: invalid length or speed limit: "
              << length << " " << speed_limit << "\n"
              << "Minimum length: " << MIN_RAIL_LENGTH << "\n"
              << "Minimum speed limit: " << MIN_SPEED_LIMIT;
    throw std::runtime_error(error.str());
  }
  std::string key = node1 > node2 ? node2 + "-" + node1 : node1 + "-" + node2;
  auto it = std::find(rails.begin(), rails.end(), key);
  if (it == rails.end()) {
    rails.push_back(Rail(node1, node2));
    it = rails.end() - 1;
  }
  // No need to remove the rail because program will exit on fail
  it->add_path(length * 1000, speed_limit / 3.6);
}

void Railway_factory::create_train(const std::string &name,
                                   double weight,
                                   double friction_coefficient,
                                   double max_acceleration_force,
                                   double max_break_force,
                                   const std::string &departure_station,
                                   const std::string &arrival_station,
                                   const std::string &departure_time,
                                   const std::string &stop_duration,
                                   std::vector<Train> &trains,
                                   std::vector<std::string> &nodes) {
  if (std::find(nodes.begin(), nodes.end(), departure_station) == nodes.end() ||
      std::find(nodes.begin(), nodes.end(), arrival_station) == nodes.end()) {
    throw std::runtime_error("Departure or arrival station not found");
  }
  Train train(name, weight * 1000, friction_coefficient,
              max_acceleration_force * 1000, max_break_force * 1000,
              departure_station, arrival_station,
              Time(departure_time), Time(stop_duration));
  if (std::find(trains.begin(), trains.end(), train) != trains.end()) {
    throw std::runtime_error("Train already exists");
  }
  trains.push_back(train);
}
