/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:27 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/06 11:04:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>

class Account {
  private:
    int _id;
    int _value;
    int _debt;

    Account();

  public:
    Account(int id, int value);
    Account(const Account &copy);
    Account &operator=(const Account &copy);
    bool operator==(int id);
    ~Account();
    std::string get_account_info() const;
    const int &get_value() const;
    const int &get_debt() const;
    void deposit(int value);
    void withdrawal(int value);
    void loan(int value, float interest_rate);
    void repay_loan(int value);
};

std::ostream &operator<<(std::ostream &out, const Account &account);
