/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:24 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/01 16:17:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bank.hpp"

Bank::Bank()
  : _liquidity(0) {}

Bank::Bank(long long liquidity)
  : _liquidity(liquidity) {}

Bank::Bank(const Bank &copy)
  : _liquidity(copy._liquidity), _accounts(copy._accounts) {}

Bank &Bank::operator=(const Bank &copy) {
  _liquidity = copy._liquidity;
  _accounts = copy._accounts;
  return *this;
}

Bank::~Bank() {}

std::string Bank::get_bank_info() const {
  std::ostringstream out;
  std::vector<Account>::const_iterator it = _accounts.begin();
  std::vector<Account>::const_iterator end = _accounts.end();
  out << "Liquidity: " << _liquidity << "\n----------\n"
      << "Accounts:\n----------\n";
  for (; it != end; it++) {
    out << it->get_account_info() << "\n----------\n";
  }
}

std::ostream &operator<<(std::ostream &out, const Bank &bank) {
  return out << bank.get_bank_info();
}
