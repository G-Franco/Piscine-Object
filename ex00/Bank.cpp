/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:22 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/25 16:04:18 by gacorrei         ###   ########.fr       */
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

int Bank::open_account(unsigned long value)
{
    int id = get_valid_id();

    if (value < 100)
    {
        std::cerr << RED << "Opening an account requires an initial deposit of 100\n" << DEFAULT;
        return id;
    }
    if (id == -1)
    {
        std::cerr << RED << "Maximum amount of accounts reached\n" << DEFAULT;
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
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
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
    // if (id <= INT_MAX)
    // THIS IS ONLY FOR TESTING PURPOSES!!
    if (id < 10)
        return id;
    return -1;
}

void Bank::deposit(int account_id, unsigned long value)
{
    if (value < 10)
    {
        std::cerr << RED << "Deposit amount must be at least 10\n" << DEFAULT;
        return;
    }
    unsigned long acc_deposit = value * 0.95;
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
        return;
    }
    std::cout << BLUE << "Account id: " << account_id << " was credited: " << acc_deposit << "\n" << DEFAULT;
    _liquidity += value;
    acc->deposit(acc_deposit);
}

void Bank::withdrawal(int account_id, unsigned long value)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
        return;
    }
    if (value > acc->get_value())
    {
        std::cerr << RED << "Amount exceeds account value\n" << DEFAULT;
        return;
    }
    std::cout << BLUE << "Account id: " << account_id << " was charged: " << value << "\n" << DEFAULT;
    acc->withdrawal(value);
}

void Bank::loan(int account_id, unsigned long amount)
{
    if (amount < 50)
    {
        std::cerr << RED << "Loan amount must be at least 50\n" << DEFAULT;
        return;
    }
    if (amount > _liquidity)
    {
        std::cerr << RED << "Loan amount exceeds bank liquidity\n" << DEFAULT;
        return;
    }
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
        return;
    }
    _liquidity -= amount;
    acc->deposit(amount);
}

void Bank::inflation_machine(unsigned long amount)
{
    if (amount < 100)
    {
        std::cerr << RED << "Extra funds must be greater than 100\n" << DEFAULT;
        return;
    }
    _liquidity += amount;
}

void Bank::invest_in_crypto(unsigned long amount)
{
    if (_liquidity < amount)
    {
        std::cerr << RED << "Investment amount exceeds liquidity\n" << DEFAULT;
        return;
    }
    _liquidity -= amount;
}

void Bank::print_account_info(int account_id)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
        return;
    }
    std::cout << *acc << "\n";
}

std::ostream &Bank::print_accounts(std::ostream &out) const
{
    std::vector<Account>::const_iterator it = _clientAccounts.begin();
    std::vector<Account>::const_iterator end = _clientAccounts.end();

    out << "Bank information: " << "\n";
    out << "Liquidity: " << (_liquidity > 0 ? GREEN : RED) << _liquidity << "\n" << DEFAULT;
    for (; it != end; it++)
        out << *it << "\n";
    return out;
}

std::ostream &operator<<(std::ostream &out, const Bank &bank)
{
    return bank.print_accounts(out);
}
