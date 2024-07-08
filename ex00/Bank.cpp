/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:22 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/08 14:12:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank() : liquidity(0), size(0) {}

Bank::Bank(const Bank &copy) {}

Bank::~Bank() {}

Bank &Bank::operator=(const Bank &copy) {}

const long long &Bank::get_liquidity() const
{
    return liquidity;
}

const std::vector<Account> &Bank::get_accounts() const
{
    return clientAccounts;
}

void Bank::open_account(long long value)
{
    if (clientAccounts.empty())
    {
        clientAccounts.push_back(Account(0, value));
        return;
    }

    int id = get_valid_id();

    if (id == -1)
    {
        std::cout << "Maximum amount of accounts reached\n";
        return;
    }
    clientAccounts.push_back(Account(id, value));
    liquidity += value;
    size++;
}

void Bank::close_account(Account &account)
{
    std::vector<Account>::iterator acc = std::find(clientAccounts.begin(), clientAccounts.end(), account);
    if (acc == clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    liquidity -= acc->get_value();
    clientAccounts.erase(acc);
    size--;
}

int Bank::get_valid_id()
{
    int id = 0;

    for (; id < size; id++)
        if (std::find(clientAccounts.begin(), clientAccounts.end(), id) == clientAccounts.end())
            return id;
    return -1;
}

void Bank::deposit(Account &account, long long value)
{
    std::vector<Account>::iterator acc = std::find(clientAccounts.begin(), clientAccounts.end(), account);
    if (acc == clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    acc->deposit(value);
}

void Bank::withdrawal(Account &account, long long value)
{
    std::vector<Account>::iterator acc = std::find(clientAccounts.begin(), clientAccounts.end(), account);
    if (acc == clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    acc->withdrawal(value);
}

std::ostream &operator<<(std::ostream &out, const Bank &bank)
{
    const std::vector<Account> accounts = bank.get_accounts();
    std::vector<Account>::const_iterator it = accounts.begin();
    std::vector<Account>::const_iterator end = accounts.end();

    out << "Bank informations : " << std::endl;
    out << "Liquidity : " << bank.get_liquidity() << std::endl;
    for (; it != end; it++)
        out << *it << std::endl;
    return out;
}
