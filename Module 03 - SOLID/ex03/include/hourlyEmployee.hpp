/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:10:23 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 17:13:46 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "employee.hpp"

class TempWorker : public Employee {
  private:
    TempWorker();
  public:
    TempWorker(int hourlyValue);
    TempWorker(const TempWorker &copy);
    TempWorker &operator=(const TempWorker &copy);
    ~TempWorker();
    void increment_worked_hours(int hours);
    void executeWorkday();
    void calculatePayroll();
};
