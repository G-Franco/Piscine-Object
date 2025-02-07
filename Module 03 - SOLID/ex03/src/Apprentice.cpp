/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Apprentice.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:42:23 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:48:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Apprentice.hpp"

Apprentice::Apprentice()
  : Employee(0),
    _absent_hours(0),
    _school_hours(0) {}

Apprentice::Apprentice(int hourlyValue)
  : Employee(hourlyValue),
    _absent_hours(0),
    _school_hours(0) {}

Apprentice::Apprentice(const Apprentice &copy)
  : Employee(copy),
    _absent_hours(copy._absent_hours),
    _school_hours(copy._school_hours) {}

Apprentice &Apprentice::operator=(const Apprentice &copy) {
  Employee::operator=(copy);
  _absent_hours = copy._absent_hours;
  _school_hours = copy._school_hours;
  return *this;
}

Apprentice::~Apprentice() {}

void Apprentice::increment_absent_hours(int hours) {
  _absent_hours += hours;
}

void Apprentice::increment_school_hours(int hours) {
  _school_hours += hours;
}

void Apprentice::executeWorkday() {
  _workedHours += WORKDAY_HOURS;
}

void Apprentice::calculatePayroll() {
  int worked = _hourlyValue * (_workedHours - _absent_hours - _school_hours);
  int school = _hourlyValue * _school_hours / SCHOOL_HOURS_FACTOR;
  int total = worked + school;
  std::cout << "Apprentice:\n"
            << "Hourly value: " << _hourlyValue << "\n"
            << "Worked hours: " << _workedHours << "\n"
            << "Absent hours: " << _absent_hours << "\n"
            << "School hours: " << _school_hours << "\n"
            << "Total: "<< total << "\n";
  _absent_hours = 0;
  _school_hours = 0;
  _workedHours = 0;
}
