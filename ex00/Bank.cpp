/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:22 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/22 17:08:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank() : _liquidity(1000), _size(0) {}

Bank::Bank(unsigned long liquidity) : _liquidity(liquidity), _size(0) {}

Bank::Bank(const Bank &copy)
{
    (void)copy;
}

Bank::~Bank() {}

Bank &Bank::operator=(const Bank &copy)
{
    (void)copy;
    return *this;
}

const unsigned long &Bank::get_liquidity() const
{
    return _liquidity;
}

const std::vector<Account> &Bank::get_accounts() const
{
    return _clientAccounts;
}

int Bank::open_account(unsigned long value)
{
    int id = get_valid_id();

    if (id == -1)
    {
        std::cout << "Maximum amount of accounts reached\n";
        return id;
    }
    _clientAccounts.push_back(Account(id, 0));
    this->deposit(id, value);
    _size++;
    return id;
}

void Bank::close_account(int account_id)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    _liquidity -= acc->get_value();
    _clientAccounts.erase(acc);
    _size--;
}

int Bank::get_valid_id()
{
    unsigned int id = 0;

    if (!_size)
        return 0;
    for (; id < _size; id++)
        if (std::find(_clientAccounts.begin(), _clientAccounts.end(), id) == _clientAccounts.end())
            return id;
    if (id <= INT_MAX)
        return id;
    return -1;
}

void Bank::deposit(int account_id, unsigned long value)
{
    unsigned long acc_deposit = value * 0.95;
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    std::cout << "Account id: " << account_id << " was credited: " << acc_deposit << "\n";
    _liquidity += value;
    acc->deposit(acc_deposit);
}

void Bank::withdrawal(int account_id, unsigned long value)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    std::cout << "Account id: " << account_id << " was charged: " << value << "\n";
    acc->withdrawal(value);
}

void Bank::loan(int account_id, unsigned long amount)
{
    if (amount > _liquidity)
    {
        std::cout << "Loan amount exceeds bank liquidity\n";
        return;
    }
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    _liquidity -= amount;
    acc->deposit(amount);
}

void Bank::inflation_machine(unsigned long amount)
{
    _liquidity += amount;
}

void Bank::invest_in_crypto(unsigned long amount)
{
    if (_liquidity < amount)
    {
        std::cout << "Investment amount exceeds liquidity\n";
        return;
    }
    _liquidity -= amount;
}

void Bank::print_account_info(int account_id)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cout << "Could not find specified account\n";
        return;
    }
    std::cout << *acc << "\n";
}

std::ostream &operator<<(std::ostream &out, const Bank &bank)
{
    const std::vector<Account> accounts = bank.get_accounts();
    std::vector<Account>::const_iterator it = accounts.begin();
    std::vector<Account>::const_iterator end = accounts.end();

    out << "Bank informations : " << "\n";
    out << "Liquidity : " << bank.get_liquidity() << "\n";
    for (; it != end; it++)
        out << *it << "\n";
    return out;
}
