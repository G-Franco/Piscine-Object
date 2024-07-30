/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:22 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/30 16:37:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank() : _liquidity(1000), _size(0) {}

Bank::Bank(long liquidity) : _liquidity(liquidity), _size(0)
{
    if (liquidity <= 0)
    {
        std::cerr << RED << "Bank liquidity must be positive\n" << DEFAULT;
        throw std::invalid_argument("Bank creation aborted");
    }
}

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

int Bank::open_account(long value)
{
    int id = get_valid_id();

    if (value > INT_MAX || value < INT_MIN)
    {
        std::cerr << RED << "Overflow when opening account\n" << DEFAULT;
        return -1;
    }
    if (value < 100)
    {
        std::cerr << RED << "Opening an account requires an initial deposit of 100\n" << DEFAULT;
        return -1;
    }
    if (id == -1)
    {
        std::cerr << RED << "Maximum amount of accounts reached\n" << DEFAULT;
        return -1;
    }
    _clientAccounts.push_back(Account(id, 0));
    this->deposit(id, value, true);
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

void Bank::deposit(int account_id, long value, bool open)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
        return;
    }
    if (value > INT_MAX || value < INT_MIN || INT_MAX - acc->get_value() < value)
    {
        std::cerr << RED << "Overflow in deposit\n" << DEFAULT;
        return;
    }
    if (value < 10)
    {
        std::cerr << RED << "Deposit amount must be at least 10\n" << DEFAULT;
        return;
    }
    long acc_deposit = value * 0.95;
    if (INT_MAX - _liquidity < value)
    {
        std::cerr << RED << "Overflow in bank liquidity during deposit\n" << DEFAULT;
        return;
    }
    _liquidity += value;
    if (INT_MAX - acc->get_value() < acc_deposit)
    {
        std::cerr << RED << "Overflow in account value during deposit\n" << DEFAULT;
        return;
    }
    acc->deposit(acc_deposit);
    std::cout << BLUE << "Account id: " << account_id << (open ? " was opened with a deposit of: " : " was credited: ") << acc_deposit << "\n" << DEFAULT;
}

void Bank::withdrawal(int account_id, long value)
{
    if (value <= 0)
    {
        std::cerr << RED << "Withdrawal amount must be greater than 0\n" << DEFAULT;
        return;
    }
    if (value > INT_MAX)
    {
        std::cerr << RED << "Overflow in withdrawal\n" << DEFAULT;
        return;
    }
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
    acc->withdrawal(value);
    std::cout << BLUE << "Account id: " << account_id << " was charged: " << value << "\n" << DEFAULT;
}

void Bank::loan(int account_id, long amount)
{
    std::vector<Account>::iterator acc = std::find(_clientAccounts.begin(), _clientAccounts.end(), account_id);
    if (acc == _clientAccounts.end())
    {
        std::cerr << RED << "Could not find specified account\n" << DEFAULT;
        return;
    }
    if (amount > INT_MAX || amount < INT_MIN || INT_MAX - acc->get_value() < amount)
    {
        std::cerr << RED << "Overflow in loan\n" << DEFAULT;
        return;
    }
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
    _liquidity -= amount;
    acc->deposit(amount);
    std::cout << BLUE << "Account id: " << account_id << " was loaned: " << amount << "\n" << DEFAULT;
}

void Bank::inflation_machine(long amount)
{
    if (amount > INT_MAX)
    {
        std::cerr << RED << "Overflow in inflation machine\n" << DEFAULT;
        return;
    }
    if (amount < 100)
    {
        std::cerr << RED << "Extra funds must be greater than 100\n" << DEFAULT;
        return;
    }
    _liquidity += amount;
    std::cout << BLUE << "Bank liquidity was increased by: " << amount << "\n" << DEFAULT;
}

void Bank::invest_in_crypto(long amount)
{
    if (amount > INT_MAX)
    {
        std::cerr << RED << "Overflow in investment\n" << DEFAULT;
        return;
    }
    if (amount < 100)
    {
        std::cerr << RED << "Investment amount must be greater than 100\n" << DEFAULT;
        return;
    }
    if (_liquidity < amount)
    {
        std::cerr << RED << "Investment amount exceeds liquidity\n" << DEFAULT;
        return;
    }
    _liquidity -= amount;
    std::cout << BLUE << "Bank investment: " << amount << "\n" << DEFAULT;
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
