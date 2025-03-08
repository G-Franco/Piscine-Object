/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:55:32 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/08 12:13:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>

// TODO: Check if using travel time is better than distance,
// some trains may have a lower sped limit than the path which 
// would increase travel time
struct Path {
  double _length;
  double _speed_limit;
  double _travel_time;

  Path(double length, double speed_limit)
    : _length(length),
      _speed_limit(speed_limit),
      _travel_time(length / speed_limit) {}

    // Paths are sorted by travel time, or by shorter length for equal travel time
    bool operator<(const Path &other) const {
    return _travel_time < other._travel_time ||
      (_travel_time == other._travel_time && _length < other._length);
    }

    bool operator==(const Path &other) const {
      return _length == other._length && _speed_limit == other._speed_limit;
    }
};

// Using a set instead of a vector keeps the paths sorted by length
struct Rail {
  std::string _node1;
  std::string _node2;
  std::set<Path> _paths;

  Rail(std::string node1, std::string node2)
    : _node1(node1), _node2(node2) {}

  bool add_path(double length, double speed_limit) {
    Path path(length, speed_limit);
    if (_paths.find(path) != _paths.end()) {
      std::cout << "Error: duplicate path\n";
      return false;
    }
    _paths.insert(path);
    return true;
  }
};
