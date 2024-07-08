/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:04 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/08 14:10:17 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account() {}

Account::Account(int id, long long value) : id(id), value(value) {}

Account::Account(const Account &copy) {}

Account::~Account() {}

Account &Account::operator=(const Account &copy)
{
    return *this;
}

bool Account::operator==(int test) const
{
    return id == test;
}

const int &Account::get_id() const
{
    return id;
}

const long long &Account::get_value() const
{
    return value;
}

void Account::deposit(long long amount)
{
    value += amount;
}

void Account::withdrawal(long long amount)
{
    if (amount > value)
    {
        std::cout << "Amount exceeds account value\n";
        return;
    }
    value -= amount;
}

std::ostream &operator<<(std::ostream &out, const Account &account)
{
    out << "[" << account.get_id() << "] - [" << account.get_value() << "]";
    return out;
}
