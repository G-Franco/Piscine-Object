/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:34:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 11:27:25 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

// TODO: This will probably need more functions
struct Time {
  int _hours;
  int _minutes;

  Time(int hours, int minutes)
    : _hours(hours), _minutes(minutes) {
    if (_hours < 0 || _hours > 23 ||
        _minutes < 0 || _minutes > 59) {
      _hours = -1;
      _minutes = -1;
    }
  }
  
  Time(const std::string &str)
    : _hours(std::stoi(str.substr(0, 2))),
      _minutes(std::stoi(str.substr(3, 2))) {
    if (_hours < 0 || _hours > 23 ||
        _minutes < 0 || _minutes > 59) {
      _hours = -1;
      _minutes = -1;
    }
  }
};
