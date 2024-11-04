/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:27 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/04 10:03:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>

class Account {
  private:
    int _id;
    int _value;

    Account();

  public:
    Account(int id, int value);
    Account(const Account &copy);
    Account &operator=(const Account &copy);
    bool operator==(int id);
    ~Account();
    std::string get_account_info() const;
    void deposit(int value);
    void withdrawal(int value);
    void loan(int value);
};

std::ostream &operator<<(std::ostream &out, const Account &account);
