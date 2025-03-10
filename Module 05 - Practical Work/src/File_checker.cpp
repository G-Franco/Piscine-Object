/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_checker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:00:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/10 15:23:13 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../include/File_checker.hpp"
#include "../include/Train.hpp"
#include "../include/helper.hpp"
#include "../include/Node_validation.hpp"
#include "../include/Rail_validation.hpp"
#include "../include/Train_validation.hpp"

File_checker::File_checker(const std::string &rail_file, const std::string &train_file)
  : _rail_file(rail_file),
    _train_file(train_file) {
  set_validation_steps();
}

File_checker::~File_checker() {}

// Checks for file existence, emptiness and readability
bool File_checker::check_file(std::ifstream &file, const std::string &file_name) {
  if (!file.is_open()) {
    std::cout << "Error: could not open " << file_name << "\n";
    return false;
  }
  if (file.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Error: " << file_name << " is empty\n";
    return false;
  }
  if (!file.good()) {
    std::cout << "Error: " << file_name << " is corrupted or unreadable\n";
    return false;
  }
  return true;
}

bool File_checker::validate_files() {
  if (!check_file(_rail_file, "rail") ||
      !check_file(_train_file, "train")) {
    return false;
  }
  // Loop through all validation steps, call validate on each strategy
  // while passing the appropriate file
  for (auto &step : _steps) {
    if (!step.first->validate(step.second)) {
      return false;
    }
  }
  return true;
}

void File_checker::set_validation_steps() {
  _steps.push_back(std::make_pair(
    std::make_unique<Node_validation>(_nodes, _rails, _trains),
    std::ref(_rail_file)));
  _steps.push_back(std::make_pair(
    std::make_unique<Rail_validation>(_nodes, _rails, _trains),
    std::ref(_rail_file)));
  _steps.push_back(std::make_pair(
    std::make_unique<Train_validation>(_nodes, _rails, _trains),
    std::ref(_train_file)));
}

// bool File_checker::validate_network() {
  // TODO: Implement network validation
  // Check if all nodes are connected (no islands)
// }

void File_checker::test_print() {
  std::cout << "Nodes:\n";
  for (const auto &node : _nodes) {
    std::cout << node << "\n";
  }
  std::cout << "\nRails:\n";
  for (const auto &rail : _rails) {
    std::cout << rail._name << "\n";
    for (const auto &path : rail._paths) {
      std::cout << "  " << path._length << " " << path._speed_limit << "\n";
    }
  }
  std::cout << "\nTrains:\n";
  for (const auto &train : _trains) {
    std::cout << train.get_name() << "\n";
  }
}
