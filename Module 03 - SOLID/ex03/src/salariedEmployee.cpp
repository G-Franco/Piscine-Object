/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:24:28 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:32:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/salariedEmployee.hpp"

ContractEmployee::ContractEmployee()
  : Employee(0),
    _absent_hours(0) {}

ContractEmployee::ContractEmployee(int hourlyValue)
  : Employee(hourlyValue),
    _absent_hours(0) {}

ContractEmployee::ContractEmployee(const ContractEmployee &copy)
  : Employee(copy),
    _absent_hours(copy._absent_hours) {}

ContractEmployee &ContractEmployee::operator=(const ContractEmployee &copy) {
  Employee::operator=(copy);
  _absent_hours = copy._absent_hours;
  return *this;
}

ContractEmployee::~ContractEmployee() {}

void ContractEmployee::increment_absent_hours(int hours) {
  _absent_hours += hours;
}

void ContractEmployee::executeWorkday() {
  _workedHours += WORKDAY_HOURS;
}

void ContractEmployee::calculatePayroll() {
  std::cout << "Contract employee:\n"
            << "Hourly value: " << _hourlyValue << "\n"
            << "Worked hours: " << _workedHours << "\n"
            << "Absent hours: " << _absent_hours << "\n"
            << "Total: " << _hourlyValue * (_workedHours - _absent_hours) << "\n";
  _absent_hours = 0;
  _workedHours = 0;
}
