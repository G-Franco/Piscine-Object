/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Apprentice.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:33:56 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/08 11:13:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "employee.hpp"

#define SCHOOL_HOURS_FACTOR 2

class Apprentice : public Employee {
  private:
    int _absent_hours;
    int _school_hours;

    Apprentice();

  public:
    Apprentice(int hourlyValue);
    Apprentice(const Apprentice &copy);
    Apprentice &operator=(const Apprentice &copy);
    ~Apprentice();
    void increment_absent_hours(int hours);
    void increment_school_hours(int hours);
    void executeWorkday();
    void calculatePayroll();
};
