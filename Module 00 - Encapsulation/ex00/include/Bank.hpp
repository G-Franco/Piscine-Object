/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:19 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/11 13:08:05 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stack>

#define COMMISSION 0.05
#define INTEREST 1.1
#ifdef TEST
#define MAX_ACCOUNTS 5
#else
#define MAX_ACCOUNTS std::numeric_limits<int>::max()
#endif

class Bank {
  private:
    class Account {
    private:
      int _id;
      int _value;
      int _debt;

      Account(int id, int value);
      Account &operator=(const Account &copy);
      bool operator==(int id);

    public:
      Account();
      Account(const Account &copy);
      ~Account();
      const std::string get_account_info() const;
      const int &get_value() const;
      const int &get_debt() const;

      friend class Bank;
    };

    long _liquidity;
    std::map<int, Account> _accounts;
    int _current_id;
    std::stack<int> _reusable_ids;

    Bank();
    Bank(const Bank &copy);
    Bank &operator=(const Bank &copy);

  public:
    Bank(long liquidity);
    ~Bank();
    std::string get_bank_info() const;
    std::string get_account_info(int id) const;
    int get_id();
    int open_account(int value);
    void close_account(int id);
    void deposit(int id, int value);
    void withdrawal(int id, int value);
    void loan(int id, int value);
    void repay_loan(int id, int value);

    Account &operator[](int id);
    const Account &operator[](int id) const;
};

std::ostream &operator<<(std::ostream &out, const Bank &bank);
