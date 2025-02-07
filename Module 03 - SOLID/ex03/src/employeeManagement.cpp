/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:16 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 16:22:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/employeeManagement.hpp"

EmployeeManager::EmployeeManager() {}

EmployeeManager::EmployeeManager(const EmployeeManager &copy) {
  *this = copy;
}

EmployeeManager &EmployeeManager::operator=(const EmployeeManager &copy) {
  if (this != &copy) {
    _employees = copy._employees;
  }
  return *this;
}

EmployeeManager::~EmployeeManager() {}

void EmployeeManager::addEmployee(Employee *employee) {
  if (employee == NULL) {
    std::cout << "Employee is NULL\n";
    return;
  }
  if (std::find(_employees.begin(), _employees.end(), employee) != _employees.end()) {
    std::cout << "Employee has already been added\n";
    return;
  }
  _employees.push_back(employee);
}

void EmployeeManager::removeEmployee(Employee *employee) {
  if (employee == NULL) {
    std::cout << "Employee is NULL\n";
    return;
  }
  std::vector<Employee*>::iterator it = std::find(_employees.begin(), _employees.end(), employee);
  if (it != _employees.end()) {
    _employees.erase(it);
  }
  else {
    std::cout << "Employee not found\n";
  }
}

void EmployeeManager::executeWorkday() {
  for (std::vector<Employee*>::iterator it = _employees.begin(); it != _employees.end(); it++) {
    (*it)->executeWorkday();
  }
}

void EmployeeManager::calculatePayroll() {
  for (std::vector<Employee*>::iterator it = _employees.begin(); it != _employees.end(); it++) {
    (*it)->calculatePayroll();
  }
}
