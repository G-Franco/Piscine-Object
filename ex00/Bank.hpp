/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:16:54 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/30 17:55:16 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <climits>
#include "Account.hpp"
#include "Colors.hpp"

class Bank
{
    private:
        long _liquidity;
        std::vector<Account> _clientAccounts;
        int _size;
        Bank(const Bank &copy);
        Bank &operator=(const Bank &copy);
    
    public:
        Bank();
        Bank(long liquidity);
        ~Bank();
        int open_account(int value);
        int get_valid_id();
        void close_account(int account_id);
        void deposit(int account_id, int value);
        void withdrawal(int account_id, int value);
        void loan(int account_id, int amount);
        void inflation_machine(int amount);
        void invest_in_crypto(int amount);
        void print_account_info(int account_id);
        std::ostream &print_accounts(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const Bank &bank);
