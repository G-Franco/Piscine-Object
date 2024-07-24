/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:16:39 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/24 16:32:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Account
{
private:
    int _id;
    unsigned long _value;
    Account();

public:
    Account(int id, unsigned long value);
    Account(const Account &copy);
    Account &operator=(const Account &copy);
    bool operator==(int test) const;
    ~Account();
    const int &get_id() const;
    const unsigned long &get_value() const;
    void deposit(unsigned long amount);
    void withdrawal(unsigned long amount);
};

std::ostream &operator<<(std::ostream &out, const Account &account);
