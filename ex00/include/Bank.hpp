/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:19 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/04 11:35:39 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <stack>
#include <limits>
#include "Account.hpp"

#define COMMISSION 0.05
#ifdef TEST
#define MAX_ACCOUNTS 5
#else
#define MAX_ACCOUNTS std::numeric_limits<int>::max()
#endif

class Bank {
  private:
    long long _liquidity;
    std::map<int, Account> _accounts;
    int _current_id;
    std::stack<int> _reusable_ids;

    Bank();
    Bank(const Bank &copy);
    Bank &operator=(const Bank &copy);

  public:
    Bank(long long liquidity);
    ~Bank();
    std::string get_bank_info() const;
    std::string get_account_info(int id) const;
    int get_id();
    void open_account(int value);
    void close_account(int id);
    void deposit(int id, int value);
    void withdrawal(int id, int value);
    void loan(int id, int value);
};

std::ostream &operator<<(std::ostream &out, const Bank &bank);
