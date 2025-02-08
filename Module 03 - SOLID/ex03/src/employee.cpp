/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:33 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/08 11:38:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/employee.hpp"

Employee::Employee()
  : _hourlyValue(0),
    _workedHours(0) {}

Employee::Employee(int hourlyValue)
  : _hourlyValue(hourlyValue),
    _workedHours(0) {}

Employee::Employee(const Employee &copy)
  : _hourlyValue(copy._hourlyValue),
    _workedHours(copy._workedHours) {}

Employee &Employee::operator=(const Employee &copy) {
  _hourlyValue = copy._hourlyValue;
  _workedHours = copy._workedHours;
  return *this;
}

Employee::~Employee() {}
