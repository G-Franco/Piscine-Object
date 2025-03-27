/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timetable.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:38:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/26 15:18:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Timetable.hpp"

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

void Timetable::set_times(const Time &start, double wait_time) {
  if (!_reversed) {
    for (const Section &section : _route) {
      // Need dijkstra to calculate the time to get to the next section
    }
  }
  else {
    
  }
}

void Timetable::reverse() {
  _reversed = !_reversed;
}
