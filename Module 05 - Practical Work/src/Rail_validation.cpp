/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rail_validation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:16:34 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/13 15:18:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Rail_validation.hpp"
#include <sstream>

Rail_validation::Rail_validation(std::vector<std::string> &nodes,
                                 std::vector<Rail> &rails,
                                 std::vector<Train> &trains)
  : AValidation(nodes, rails, trains) {}

// Rail line format:
// Rail node1 node2 length speed_limit
bool Rail_validation::validate(std::ifstream &file) {
  std::string line;
  int line_number = _nodes.size();
  while (getline(file, line)) {
    std::string rail;
    std::string node1;
    std::string node2;
    double length;
    double speed_limit;
    std::string extra;
    std::istringstream read(line);

    line_number++;
    if (!(read >> rail >> node1 >> node2 >> length >> speed_limit) ||
        read >> extra ||
        rail != "Rail") {
      std::cout << "Error: invalid Rail format on line " << line_number << ": "
                << line << "\n";
      return false;
    }
    try {
      _factory.create_rail(node1, node2, length, speed_limit, _nodes, _rails);
    }
    catch (std::exception &e) {
      std::cout << "Error with rail info on line " << line_number << ": "
                << line << "\n" << e.what() << "\n";
      return false;
    }
  }
  if (_rails.empty()) {
    std::cout << "Error: no rails found\n";
    return false;
  }
  return true;
}
