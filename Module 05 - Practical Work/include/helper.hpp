/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:55:32 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/17 17:48:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

struct Path {
  double _length; // m
  double _speed_limit; // m/s

  Path(double length, double speed_limit)
    : _length(length),
      _speed_limit(speed_limit) {}

    bool operator==(const Path &other) const {
      return _length == other._length && _speed_limit == other._speed_limit;
    }
};

struct Rail {
  std::string _name;
  std::string _node1;
  std::string _node2;
  std::vector<Path> _paths;

  Rail(std::string node1, std::string node2)
    : _name(node1 < node2 ? node1 + "-" + node2 : node2 + "-" + node1),
      _node1(node1),
      _node2(node2) {}

    bool operator==(const Rail &other) const {
      return _name == other._name;
    }

    bool operator==(const std::string &key) const {
      return _name == key;
    }

    void add_path(double length, double speed_limit) {
    Path path(length, speed_limit);
    if (std::find(_paths.begin(), _paths.end(), path) != _paths.end()) {
      throw std::runtime_error("Duplicate path for rail " + _name);
    }
    _paths.push_back(path);
  }
};

struct Section {
  std::string _start_node;
  std::string _finish_node;
  Time _start_time;
  Time _finish_time;
  int _travel_time;
  int _acceleration_duration;
  int _maintain_speed_duration;
  int _deceleration_duration;

  Section(std::string start_node,
          std::string finish_node,
          Time start_time,
          Time finish_time,
          int travel_time,
          int acceleration_duration,
          int maintain_speed_duration,
          int deceleration_duration)
    : _start_node(start_node),
      _finish_node(finish_node),
      _start_time(start_time),
      _finish_time(finish_time),
      _travel_time(travel_time),
      _acceleration_duration(acceleration_duration),
      _maintain_speed_duration(maintain_speed_duration),
      _deceleration_duration(deceleration_duration) {}

  void reverse(Time start_time, Time finish_time) {
    std::swap(_start_node, _finish_node);
    _start_time = start_time;
    _finish_time = finish_time;
  }
};
