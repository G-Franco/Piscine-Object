/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Train_validation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:55:33 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 17:18:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Train_validation.hpp"
#include <sstream>

Train_validation::Train_validation(std::vector<std::string> &nodes,
                                   std::vector<Rail> &rails,
                                   std::vector<Train> &trains)
  : AValidation(nodes, rails, trains) {}

// Train line format:
// TrainXY weight friction_coefficient max_acceleration_force max_break_force
// departure_node arrival_node departure_time _stop_duration
bool Train_validation::validate(std::ifstream &file) {
  std::string line;
  while (getline(file, line)) {
    std::string name;
    double weight;
    double friction_coefficient;
    double max_acceleration_force;
    double max_break_force;
    std::string departure_station;
    std::string arrival_station;
    std::string departure_time;
    std::string stop_duration;
    std::string extra;
    std::istringstream read(line);

    if (!(read >> name >> weight >> friction_coefficient
        >> max_acceleration_force >> max_break_force
        >> departure_station >> arrival_station
        >> departure_time >> stop_duration) ||
        read >> extra ||
        name.size() < 6 ||
        name.substr(0, 5) != "Train") { 
      std::cout << "Error: invalid Train line format: " << line << "\n";
      return false;
    }
    try {
      _factory.create_train(name, weight, friction_coefficient,
                            max_acceleration_force, max_break_force,
                            departure_station, arrival_station,
                            departure_time, stop_duration, _trains, _nodes);
    }
    catch (std::exception &e) {
      std::cout << "Error with train info on line " << line << "\n"
                << e.what() << "\n";
      return false;
    }
  }
  if (_trains.empty()) {
    std::cout << "Error: no trains found\n";
    return false;
  }
  return true;
}
