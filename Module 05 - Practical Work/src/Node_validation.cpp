/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_validation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:04:06 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/13 15:18:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Node_validation.hpp"
#include <sstream>

Node_validation::Node_validation(std::vector<std::string> &nodes,
                                 std::vector<Rail> &rails,
                                 std::vector<Train> &trains)
  : AValidation(nodes, rails, trains) {}

// Node line format:
// Node node_name
bool Node_validation::validate(std::ifstream &file) {
  std::string line;
  int line_number = 0;
  while (getline(file, line)) {
    std::string node;
    std::string node_name;
    std::string extra;
    std::istringstream read(line);

    line_number++;
    if (!(read >> node >> node_name) ||
        (read >> extra) ||
        node != "Node") {
      std::cout << "Error: invalid Node format on line " << line_number << ": "
                << line << "\n";
      return false;
    }

    try {
      _factory.create_node(node_name, _nodes);
    }
    catch (std::exception &e) {
      std::cout << "Error with node info on line " << line_number << ": "
                << line << "\n" << e.what() << "\n";
      return false;
    }

    // Checking if the next line starts with 'N' for Node
    // If not, there should be no more nodes and rails are next
    int next = file.peek();
    if (next != 'N') {
      return true;
    }
  }

  if (_nodes.empty()) {
    std::cout << "Error: no nodes found\n";
    return false;
  }
  return true;
}
