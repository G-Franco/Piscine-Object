/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:24 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/11 14:20:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bank.hpp"

Bank::Bank()
  : _liquidity(0),
  _current_id(1) {}

Bank::Bank(long liquidity)
  : _liquidity(liquidity),
  _current_id(1) {}

Bank::Bank(const Bank &copy)
  : _liquidity(copy._liquidity),
  _accounts(copy._accounts),
  _current_id(copy._current_id),
  _reusable_ids(copy._reusable_ids) {}

Bank &Bank::operator=(const Bank &copy) {
  _liquidity = copy._liquidity;
  _accounts = copy._accounts;
  _current_id = copy._current_id;
  _reusable_ids = copy._reusable_ids;
  return *this;
}

Bank::~Bank() {}

std::string Bank::get_bank_info() const {
  std::ostringstream out;
  std::map<int, Account>::const_iterator it = _accounts.begin();
  std::map<int, Account>::const_iterator end = _accounts.end();
  out << "Liquidity: " << _liquidity << "\n----------\n"
      << "Accounts:\n----------\n";
  for (; it != end; it++) {
    out << it->second.get_account_info() << "----------\n";
  }
  return out.str();
}

std::string Bank::get_account_info(int id) const {
  return (*this)[id].get_account_info();
}

int Bank::get_id() {
  if (!_reusable_ids.empty()) {
    int ret = _reusable_ids.top();
    _reusable_ids.pop();
    return ret;
  }
  return _current_id;
}

int Bank::open_account(int value) {
  if (value < 100) {
    throw (std::runtime_error("Cannot open an account with an amount below 100\n"));
  }
  if (_liquidity > std::numeric_limits<long>::max() - value) {
    throw (std::runtime_error("Account initial deposit would overflow bank liquidity\n"));
  }
  int id = get_id();
  if (!id) {
    throw (std::runtime_error("Account id limit reached, can't open more accounts\n"));
  }
  int bank_commission = value * COMMISSION;
  int acc_value = value - bank_commission;
  _liquidity += value;
  _accounts.insert(std::pair<int, Account>(id, Account(id, acc_value)));
  _accounts[id].get_account_info();
  if (_current_id == MAX_ACCOUNTS) {
    _current_id = 0;
  }
  else if (_current_id == id) {
    _current_id++;
  }
  std::cout << "Successfully opened account\n";
  return id;
}

void Bank::close_account(int id) {
  Account acc = (*this)[id];
  const int acc_debt = acc.get_debt();
  if (acc_debt) {
    std::ostringstream err;
    err << "Can't close account.\nOutstanding debt: " << acc_debt << "\n";
    throw (std::runtime_error(err.str()));
  }
  _reusable_ids.push(id);
  _liquidity -= acc.get_value();
  _accounts.erase(id);
  std::cout << "Successfully closed account\n";
}

void Bank::deposit(int id, int value) {
  Account acc = (*this)[id];
  if (value < 20) {
    throw (std::runtime_error("The minimum allowed deposit amount is 20\n"));
  }
  if (acc.get_value() > std::numeric_limits<int>::max() - value) {
    throw (std::runtime_error("This deposit would overflow the account value\n"));
  }
  int bank_commission = value * COMMISSION;
  int deposit_value = value - bank_commission;
  acc._value += deposit_value;
  _liquidity += value;
  std::cout << "Deposit was successful\n";
}

void Bank::withdrawal(int id, int value) {
  Account acc = (*this)[id];
  if (value < 0) {
    throw (std::runtime_error("Can't withdraw negative amount\n"));
  }
  if (acc.get_value() < value) {
    throw (std::runtime_error("Withdrawal amount cannot exceed account value\n"));
  }
  acc._value -= value;
  _liquidity -= value;
  std::cout << "Withdrawal was successful\n";
}

void Bank::loan(int id, int value) {
  Account acc = (*this)[id];
  if (value < 100) {
    throw (std::runtime_error("Minimum loan amount is 100\n"));
  }
  if (value > _liquidity) {
    throw (std::runtime_error("Loan amount cannot exceed bank liquidity\n"));
  }
  if (acc.get_value() > std::numeric_limits<int>::max() - value) {
    throw (std::runtime_error("This loan amount would overflow the account value\n"));
  }
  acc._value += value;
  acc._debt += value * INTEREST;
  std::cout << "Loan was successful\n";
}

void Bank::repay_loan(int id, int value) {
  Account acc = (*this)[id];
  if (value <= 0) {
    throw (std::runtime_error("Can't repay negative or zero amount\n"));
  }
  int acc_debt = acc.get_debt();
  if (value > acc_debt) {
    throw (std::runtime_error("Amount should not exceed debt value\n"));
  }
  acc._value -= value;
  acc._debt -= value;
  if (!acc_debt) {
    std::cout << "Debt paid in full\n";
    return;
  }
  std::cout << "Partial payment accepted, " << acc_debt << " remaining\n";
}

Bank::Account &Bank::operator[](int id) {
  try {
    return _accounts.at(id);
  } catch (std::out_of_range &e) {
    std::ostringstream err;
    err << "Provided id (" << id << ") does not match any account\n";
    throw (std::runtime_error(err.str()));
  }
}

const Bank::Account &Bank::operator[](int id) const {
  try {
    return _accounts.at(id);
  } catch (std::out_of_range &e) {
    std::ostringstream err;
    err << "Provided id (" << id << ") does not match any account\n";
    throw(std::runtime_error(err.str()));
  }
}

std::ostream &operator<<(std::ostream &out, const Bank &bank) {
  return out << bank.get_bank_info();
}
