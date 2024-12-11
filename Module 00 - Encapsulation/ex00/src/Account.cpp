/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:31 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/11 10:37:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bank.hpp"

Bank::Account::Account()
  : _id(-1),
  _value(0),
  _debt(0) {}

Bank::Account::Account(int id, int value)
  : _id(id),
  _value(value),
  _debt(0) {}

Bank::Account::Account(const Account &copy)
  : _id(copy._id),
  _value(copy._value),
  _debt(0) {}

Bank::Account &Bank::Account::operator=(const Account &copy) {
  _id = copy._id;
  _value = copy._value;
  _debt = copy._debt;
  return *this;
}

bool Bank::Account::operator==(int id) {
  return _id == id;
}

Bank::Account::~Account() {}

const std::string Bank::Account::get_account_info() const {
  std::stringstream out;
  out << "ID: " << _id << " | Value: " << _value << "\n";
  return out.str();
}

const int &Bank::Account::get_value() const {
  return _value;
}

const int &Bank::Account::get_debt() const {
  return _debt;
}
