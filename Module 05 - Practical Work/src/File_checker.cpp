/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_checker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:00:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/13 15:13:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <queue>
#include <unordered_set>
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
  make_network();
  if (!validate_network()) {
    return false;
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

void File_checker::make_network() {
  for (auto &rail : _rails) {
    _network[rail._node1].push_back(&rail);
    _network[rail._node2].push_back(&rail);
  }
}

// Make sure all nodes are connected (no isolated nodes)
// using BFS (Breadth First Search)
// Queue for FIFO
// Unordered set for O(1) searching
bool File_checker::validate_network() {
  std::queue<std::string> queue;
  std::unordered_set<std::string> visited;

  queue.push(_nodes[0]);
  visited.insert(_nodes[0]);
  while (!queue.empty()) {
    std::string current = queue.front();
    queue.pop();

    // Loop every rail connecting to current node,
    // check which node it connects to and add if not yet visited
    for (auto &entry : _network[current]) {
      std::string neighbour = entry->_node1 == current ? entry->_node2 : entry->_node1;
      // Unordered set prevents duplicates but still need to check to add
      // to queue
      if (visited.find(neighbour) == visited.end()) {
        queue.push(neighbour);
        visited.insert(neighbour);
      }
    }
  }

  // If visited and _nodes have the different sizes there are isolated nodes
  if (visited.size() != _nodes.size()) {
    std::cout << "Error: there are isolated nodes in the network\n";
    std::cout << "Isolated nodes:\n";
    for (const auto& node : _nodes) {
      if (visited.find(node) == visited.end()) {
        std::cout << "- " << node << "\n";
      }
    }
    return false;
  }
  return true;
}

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
