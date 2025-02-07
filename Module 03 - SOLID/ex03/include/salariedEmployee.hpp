/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:21:43 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:30:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "employee.hpp"

class ContractEmployee : public Employee {
  private:
    int _absent_hours;

    ContractEmployee();

  public:
    ContractEmployee(int hourlyValue);
    ContractEmployee(const ContractEmployee &copy);
    ContractEmployee &operator=(const ContractEmployee &copy);
    ~ContractEmployee();
    void increment_absent_hours(int hours);
    void executeWorkday();
    void calculatePayroll();
};