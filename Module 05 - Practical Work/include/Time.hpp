/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:34:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/01 15:52:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// TODO: This will probably need more functions
struct Time {
  int _hours;
  int _minutes;
  int _seconds;

  Time(int hours, int minutes, int seconds)
    : _hours(hours),
      _minutes(minutes),
      _seconds(seconds) {
    if (_hours < 0 || _hours > 23 ||
        _minutes < 0 || _minutes > 59 ||
        _seconds < 0 || _seconds > 59) {
      _hours = -1;
      _minutes = -1;
      _seconds = -1;
    }
  }
  
  Time(const std::string &str)
    : _hours(std::stoi(str.substr(0, 2))),
      _minutes(std::stoi(str.substr(3, 2))) {
    if (_hours < 0 || _hours > 23 ||
        _minutes < 0 || _minutes > 59) {
      _hours = -1;
      _minutes = -1;
      _seconds = -1;
    }
    _seconds = 0;
  }

  Time &operator=(const Time &copy) {
    _hours = copy._hours;
    _minutes = copy._minutes;
    _seconds = copy._seconds;
    return *this;
  }

  // TODO: Add test cases for this operation
  // Assuming duration is in seconds
  Time operator+(int duration) const {
    // This shouldn't happen, but just in case
    if (duration < 0) {
      throw std::runtime_error("[Time +] Error: Duration must be positive");
    }

    // Get a total
    int total_seconds = _hours * 3600 + _minutes * 60 + _seconds + duration;

    // Extract hours, minutes and seconds without overflowing their limits
    int hours = (total_seconds / 3600) % 24;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;
    return Time(hours, minutes, seconds);
  }

  double to_minutes() const {
    return _hours * 60 + _minutes + (_seconds / 60.0);
  }
};
