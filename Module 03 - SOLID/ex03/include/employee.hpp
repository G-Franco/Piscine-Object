/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:45:47 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:28:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define WORKDAY_HOURS 7

class Employee {
  protected:
    int _hourlyValue;
    int _workedHours;

  public:
    Employee();
    Employee(int hourlyValue);
    Employee(const Employee &copy);
    Employee &operator=(const Employee &copy);
    virtual ~Employee();
    virtual void executeWorkday() = 0;
    virtual void calculatePayroll() = 0;
};
