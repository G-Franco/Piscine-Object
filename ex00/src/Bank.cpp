/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:24 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/04 11:42:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bank.hpp"

Bank::Bank()
  : _liquidity(0),
  _current_id(1) {}

Bank::Bank(long long liquidity)
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
    out << it->second.get_account_info() << "\n----------\n";
  }
}

// TODO - Check if this is really necessary
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

// TODO - Add the money logic to open and close account
void Bank::open_account(int value) {
  if (value < 100) {
    std::cout << "Cannot open an account with an amount below 100\n";
    return;
  }
  if ( _liquidity > std::numeric_limits<long long>::max() - value) {
    std::cout << "Account initial deposit would overflow bank liquidity\n";
    return;
  }
  int id = get_id();
  if (!id) {
    std::cout << "Account id limit reached, can't open more accounts\n";
    return;
  }
  _accounts[_current_id] = Account(_current_id, value);
  std::cout << "Successfully opened account\n";
  _accounts[_current_id].get_account_info();
  if (_current_id == MAX_ACCOUNTS) {
    _current_id = 0;
  }
  else {
    _current_id++;
  }
}

void Bank::close_account(int id) {
  std::map<int, Account>::iterator entry = _accounts.find(id);
  if (entry == _accounts.end()) {
    std::cout << "Provided id (" << id << ") does not match any account\n";
    return;
  }
  std::cout << "Successfully closed account\n";
  _reusable_ids.push(id);
  _accounts.erase(entry);
}

void Bank::deposit(int id, int value) {
  
}

void Bank::withdrawal(int id, int value) {
  
}

void Bank::loan(int id, int value) {
  
}


std::ostream &operator<<(std::ostream &out, const Bank &bank) {
  return out << bank.get_bank_info();
}
