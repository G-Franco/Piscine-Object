/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:04 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/24 16:34:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account() {}

Account::Account(int id, unsigned long value) : _id(id), _value(value) {}

Account::Account(const Account &copy) : _id(copy._id), _value(copy._value) {}

Account::~Account() {}

Account &Account::operator=(const Account &copy)
{
    (void)copy;
    return *this;
}

bool Account::operator==(int test) const
{
    return _id == test;
}

const int &Account::get_id() const
{
    return _id;
}

const unsigned long &Account::get_value() const
{
    return _value;
}

void Account::deposit(unsigned long amount)
{
    _value += amount;
}

void Account::withdrawal(unsigned long amount)
{
    _value -= amount;
}

std::ostream &operator<<(std::ostream &out, const Account &account)
{
    out << "[" << account.get_id() << "] - [" << account.get_value() << "]";
    return out;
}
