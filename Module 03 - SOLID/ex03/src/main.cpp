/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:14:36 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/08 11:53:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/employeeManagement.hpp"
#include "../include/Apprentice.hpp"
#include "../include/hourlyEmployee.hpp"
#include "../include/salariedEmployee.hpp"

#define MONTH_DAYS 30

int main() {
  EmployeeManager manager;
  Apprentice apprentice(10);
  TempWorker tempWorker(20);
  ContractEmployee contractEmployee(30);
  manager.addEmployee(&apprentice);
  manager.addEmployee(&tempWorker);
  manager.addEmployee(&contractEmployee);
  
  std::cout << "Basic tests with no missed hours\n";
  for (int i = 0; i < MONTH_DAYS; i++) {
    manager.executeWorkday();
  }
  manager.calculatePayroll();

  std::cout << "\nTests with missed/school hours\n";
  for (int i = 0; i < MONTH_DAYS; i++) {
    manager.executeWorkday();
  }
  apprentice.increment_absent_hours(WORKDAY_HOURS * 3);
  apprentice.increment_school_hours(WORKDAY_HOURS * 10);
  contractEmployee.increment_absent_hours(WORKDAY_HOURS);
  tempWorker.increment_worked_hours(WORKDAY_HOURS * 2);
  manager.calculatePayroll();
}
