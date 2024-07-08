/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:16:54 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/08 14:01:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <climits>
#include "Account.hpp"

class Bank
{
    private:
        long long liquidity;
        std::vector<Account> clientAccounts;
        int size;
        Bank(const Bank &copy);
        Bank &operator=(const Bank &copy);
    public:
        Bank();
        ~Bank();
        const long long &get_liquidity() const;
        const std::vector<Account> &get_accounts() const;
        void open_account(long long value);
        int get_valid_id();
        void close_account(Account &account);
        void deposit(Account &account, long long value);
        void withdrawal(Account &account, long long value);
};

std::ostream &operator<<(std::ostream &out, const Bank &bank);
