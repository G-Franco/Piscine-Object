/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timetable.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:38:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/01 16:10:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Timetable.hpp"
#include "../include/Time.hpp"
#include "../include/helper.hpp"

Timetable::Timetable()
  : _reversed(false) {}

Timetable::Timetable(const Timetable &copy)
  : _route(copy._route),
    _reversed(copy._reversed) {}

Timetable &Timetable::operator=(const Timetable &copy) {
  _route = copy._route;
  _reversed = copy._reversed;
  return *this;
}

Timetable::~Timetable() {}

void Timetable::add_section(const Section &section) {
  _route.push_back(section);
}

void Timetable::set_times(Time start, double wait_time) {
  Time temp = start;
  for (Section &section : _route) {
    section._start_time = temp;
    section._finish_time = temp + section._travel_time;
    temp = section._finish_time + wait_time;
  }
}

void Timetable::reverse() {
  _reversed = !_reversed;
  std::reverse(_route.begin(), _route.end());
  for (auto& section : _route) {
    std::swap(section._start_node, section._finish_node);
  }
}
