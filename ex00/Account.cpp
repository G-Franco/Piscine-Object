/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:04 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/29 16:03:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Colors.hpp"

Account::Account() {}

Account::Account(int id, int value) : _id(id), _value(value) {}

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

const int &Account::get_value() const
{
    return _value;
}

void Account::deposit(int amount)
{
    _value += amount;
}

void Account::withdrawal(int amount)
{
    _value -= amount;
}

std::ostream &operator<<(std::ostream &out, const Account &account)
{
    int value = account.get_value();
    out << "[" << BLUE << account.get_id() << DEFAULT << "] - [" << (value > 0 ? GREEN : RED) << value << DEFAULT << "]";
    return out;
}
