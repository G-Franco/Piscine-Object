/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:24 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/07 11:03:12 by gacorrei         ###   ########.fr       */
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
  std::map<int, Account>::const_iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::ostringstream ret;
    ret << "Provided id (" << id << ") does not match any account\n";
    return ret.str();
  }
  return entry->second.get_account_info();
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
    std::cout << "Cannot open an account with an amount below 100\n";
    return -1;
  }
  if (_liquidity > std::numeric_limits<long>::max() - value) {
    std::cout << "Account initial deposit would overflow bank liquidity\n";
    return -1;
  }
  int id = get_id();
  if (!id) {
    std::cout << "Account id limit reached, can't open more accounts\n";
    return -1;
  }
  int bank_commission = value * COMMISSION;
  int acc_value = value - bank_commission;
  _liquidity += value;
  _accounts[id] = Account(id, acc_value);
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
  std::map<int, Account>::iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::cout << "Provided id (" << id << ") does not match any account\n";
    return;
  }
  const int acc_debt = entry->second.get_debt();
  if (acc_debt) {
    std::cout << "Can't close account.\nOutstanding debt: " << acc_debt << "\n";
    return;
  }
  _reusable_ids.push(id);
  _liquidity -= entry->second.get_value();
  _accounts.erase(entry);
  std::cout << "Successfully closed account\n";
}

void Bank::deposit(int id, int value) {
  std::map<int, Account>::iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::cout << "Provided id (" << id << ") does not match any account\n";
    return;
  }
  if (value < 20) {
    std::cout << "The minimum allowed deposit amount is 20\n";
    return;
  }
  if (entry->second.get_value() > std::numeric_limits<int>::max() - value) {
    std::cout << "This deposit would overflow the account value\n";
    return;
  }
  int bank_commission = value * COMMISSION;
  int deposit_value = value - bank_commission;
  entry->second.deposit(deposit_value);
  _liquidity += value;
  std::cout << "Deposit was successful\n";
}

void Bank::withdrawal(int id, int value) {
  std::map<int, Account>::iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::cout << "Provided id (" << id << ") does not match any account\n";
    return;
  }
  if (value < 0) {
    std::cout << "Can't withdraw negative amount\n";
    return;
  }
  if (entry->second.get_value() < value) {
    std::cout << "Withdrawal amount cannot exceed account value\n";
    return;
  }
  entry->second.withdrawal(value);
  _liquidity -= value;
  std::cout << "Withdrawal was successful\n";
}

void Bank::loan(int id, int value) {
  std::map<int, Account>::iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::cout << "Provided id (" << id << ") does not match any account\n";
    return;
  }
  if (value < 100) {
    std::cout << "Minimum loan amount is 100\n";
    return;
  }
  if (value > _liquidity) {
    std::cout << "Loan amount cannot exceed bank liquidity\n";
    return;
  }
  if (entry->second.get_value() > std::numeric_limits<int>::max() - value) {
    std::cout << "This loan amount would overflow the account value\n";
    return;
  }
  entry->second.loan(value, INTEREST);
  std::cout << "Loan was successful\n";
}

void Bank::repay_loan(int id, int value) {
  std::map<int, Account>::iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::cout << "Provided id (" << id << ") does not match any account\n";
    return;
  }
  if (value <= 0) {
    std::cout << "Value must be positive\n";
    return;
  }
  if (value > entry->second.get_debt()) {
    std::cout << "Amount should not exceed debt value\n";
    return;
  }
  entry->second.repay_loan(value);
  if (!entry->second.get_debt()) {
    std::cout << "Debt paid in full\n";
    return;
  }
  std::cout << "Partial payment accepted, " << entry->second.get_debt() << " remaining\n";
}

std::ostream &operator<<(std::ostream &out, const Bank &bank) {
  return out << bank.get_bank_info();
}
