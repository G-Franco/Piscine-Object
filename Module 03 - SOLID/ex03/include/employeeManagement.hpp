/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:37:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:18:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include "employee.hpp"

class EmployeeManager {
  private:
    std::vector<Employee*> _employees;

    EmployeeManager(const EmployeeManager &copy);
    EmployeeManager &operator=(const EmployeeManager &copy);

  public:
    EmployeeManager();
    ~EmployeeManager();
    void addEmployee(Employee *employee);
    void removeEmployee(Employee *employee);
    void executeWorkday();
    void calculatePayroll();
};
