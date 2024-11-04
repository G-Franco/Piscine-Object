/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:31 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/04 11:15:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"

Account::Account() {}

Account::Account(int id, int value)
  : _id(id),
  _value(value) {}

Account::Account(const Account &copy)
  : _id(copy._id),
  _value(copy._value) {}

Account &Account::operator=(const Account &copy) {
  _id = copy._id;
  _value = copy._value;
  return *this;
}

bool Account::operator==(int id) {
  return _id == id;
}

Account::~Account() {}

std::string Account::get_account_info() const {
  std::stringstream out;
  out << "ID: " << _id << " | Value: " << _value << "\n";
  return out.str();
}

std::ostream &operator<<(std::ostream &out, const Account &account) {
  return out << account.get_account_info();
}