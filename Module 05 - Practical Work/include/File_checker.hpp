/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_checker.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:32:34 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/08 13:05:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

struct Rail;
struct Time;
class Train;

class File_checker {
private:
  std::ifstream _rail_file;
  std::ifstream _train_file;
  // TODO: Should I use these containers or change to vectors?
  std::unordered_set<std::string> _nodes;
  std::unordered_map<std::string, Rail> _rails;
  std::vector<Train> _trains;

  // TODO: Check if these should stay here or go global
  static constexpr double MIN_RAIL_LENGTH = 5.0;
  static constexpr double MIN_SPEED_LIMIT = 100.0;

public:
  File_checker(const std::string &rail_file, const std::string &train_file);
  File_checker(const File_checker &copy) = delete;
  File_checker &operator=(const File_checker &copy) = delete;
  ~File_checker();
  bool validate_files();
  bool check_file(std::ifstream &file, const std::string &file_name);
  bool validate_nodes();
  bool validate_rails();
  bool validate_trains();
  bool add_rail(const std::string &node1, const std::string &node2, double length, double speed_limit);
};
