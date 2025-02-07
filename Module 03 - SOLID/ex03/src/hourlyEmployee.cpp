/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:13:56 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:28:56 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hourlyEmployee.hpp"

TempWorker::TempWorker()
  : Employee(0) {}

TempWorker::TempWorker(int hourlyValue)
  : Employee(hourlyValue) {}

TempWorker::TempWorker(const TempWorker &copy)
  : Employee(copy) {}

TempWorker &TempWorker::operator=(const TempWorker &copy) {
  Employee::operator=(copy);
  return *this;
}

TempWorker::~TempWorker() {}

void TempWorker::increment_worked_hours(int hours) {
  _workedHours += hours;
}

void TempWorker::executeWorkday() {
  increment_worked_hours(WORKDAY_HOURS);
}

void TempWorker::calculatePayroll() {
  std::cout << "Temp worker:\n"
            << "Hourly value: " << _hourlyValue << "\n"
            << "Worked hours: " << _workedHours << "\n"
            << "Total: " << _hourlyValue * _workedHours << "\n";
  _workedHours = 0;
}
