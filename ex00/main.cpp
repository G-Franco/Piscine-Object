/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:54 by gacorrei          #+#    #+#             */
/*   Updated: 2024/08/04 15:51:48 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Bank.hpp"

void bank_creation(long liquidity, bool def)
{
    try
    {
        if (def)
        {
            Bank united_bank_of_money;
            std::cout << united_bank_of_money;
        }
        else
        {
            Bank united_bank_of_money(liquidity);
            std::cout << united_bank_of_money;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_account_open(long bank_liq, int acc_val)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    united_bank_of_money.open_account(acc_val);
    std::cout << united_bank_of_money;
}

void test_account_close(long bank_liq, int acc_id)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    united_bank_of_money.open_account(100);
    std::cout << united_bank_of_money;
    united_bank_of_money.close_account(acc_id);
    std::cout << united_bank_of_money;
}

void test_account_deposit(long bank_liq, long acc_val, long acc_dep)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    int acc = united_bank_of_money.open_account(acc_val);
    std::cout << united_bank_of_money;
    united_bank_of_money.deposit(acc, acc_dep);
    std::cout << united_bank_of_money;
}

void test_account_withdrawal(long bank_liq, long acc_val, long acc_dep)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    int acc = united_bank_of_money.open_account(acc_val);
    std::cout << united_bank_of_money;
    united_bank_of_money.withdrawal(acc, acc_dep);
    std::cout << united_bank_of_money;
}

void test_account_loan(long bank_liq, long acc_val, long acc_loan)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    int acc = united_bank_of_money.open_account(acc_val);
    std::cout << united_bank_of_money;
    united_bank_of_money.loan(acc, acc_loan);
    std::cout << united_bank_of_money;
}

void test_inflation(long bank_liq, long bailout)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    united_bank_of_money.inflation_machine(bailout);
    std::cout << united_bank_of_money;
}

void test_invest_in_crypto(long bank_liq, long bad_decision)
{
    Bank united_bank_of_money(bank_liq);
    std::cout << united_bank_of_money;
    united_bank_of_money.invest_in_crypto(bad_decision);
    std::cout << united_bank_of_money;
}

int main()
{
    std::cout << "Test bank creation with default constructor\n";
    bank_creation(0, true);
    std::cout << "\nTest bank creation with negative initial liquidity\n";
    bank_creation(-1000, false);
    std::cout << "\nTest bank creation with 0 initial liquidity\n";
    bank_creation(0, false);
    // Uncomment to see error while compiling
    // std::cout << "\nTest bank creation with positive overflowing initial liquidity\n";
    // bank_creation(LONG_MAX + 1, false);
    std::cout << "\nTest bank creation with positive initial liquidity\n";
    bank_creation(1000, false);
    std::cout << "\nTest account creation with less than 100 initial value\n";
    test_account_open(1000, 50);
    std::cout << "\nTest account creation with negative initial value\n";
    test_account_open(1000, -100);
    std::cout << "\nTest account creation with 0 initial value\n";
    test_account_open(1000, 0);
    std::cout << "\nTest account creation with positive initial value\n";
    test_account_open(1000, 100);
    std::cout << "\nTest account creation with value that will overflow bank liquidity\n";
    test_account_open(LONG_MAX, 100);
    std::cout << "\nTest closing account with correct id\n";
    test_account_close(1000, 0);
    std::cout << "\nTest closing account with wrong positive id\n";
    test_account_close(1000, 1);
    std::cout << "\nTest closing account with wrong negative id\n";
    test_account_close(1000, -1);
    std::cout << "\nTest deposit with positive amount\n";
    test_account_deposit(1000, 100, 100);
    std::cout << "\nTest deposit with negative amount\n";
    test_account_deposit(1000, 100, -100);
    std::cout << "\nTest deposit with 0 amount\n";
    test_account_deposit(1000, 100, 0);
    std::cout << "\nTest deposit with positive amount less than 10\n";
    test_account_deposit(1000, 100, 9);
    std::cout << "\nTest deposit with value that will cause overflow\n";
    test_account_deposit(1000, INT_MAX, INT_MAX);
    std::cout << "\nTest deposit with value that will overflow bank liquidity\n";
    test_account_deposit(LONG_MAX - 100, 100, 200);
    std::cout << "\nTest withdrawal with positive amount\n";
    test_account_withdrawal(1000, 100, 50);
    std::cout << "\nTest withdrawal with negative amount\n";
    test_account_withdrawal(1000, 100, -50);
    std::cout << "\nTest withdrawal with 0 amount\n";
    test_account_withdrawal(1000, 100, 0);
    std::cout << "\nTest withdrawal with positive amount greater than account value\n";
    test_account_withdrawal(1000, 100, 200);
    std::cout << "\nTest loan with positive amount\n";
    test_account_loan(1000, 100, 100);
    std::cout << "\nTest loan with negative amount\n";
    test_account_loan(1000, 100, -100);
    std::cout << "\nTest loan with 0 amount\n";
    test_account_loan(1000, 100, 0);
    std::cout << "\nTest loan with positive amount greater than bank liquidity\n";
    test_account_loan(1000, 100, 2000);
    std::cout << "\nTest loan with value that will overflow account value\n";
    test_account_loan(1000, INT_MAX, INT_MAX);
    std::cout << "\nTest inflation machine with positive amount\n";
    test_inflation(1000, 100);
    std::cout << "\nTest inflation machine with negative amount\n";
    test_inflation(1000, -100);
    std::cout << "\nTest inflation machine with 0 amount\n";
    test_inflation(1000, 0);
    std::cout << "\nTest inflation machine with positive amount less than 100\n";
    test_inflation(1000, 99);
    std::cout << "\nTest invest in crypto with positive amount\n";
    test_invest_in_crypto(1000, 100);
    std::cout << "\nTest invest in crypto with negative amount\n";
    test_invest_in_crypto(1000, -100);
    std::cout << "\nTest invest in crypto with 0 amount\n";
    test_invest_in_crypto(1000, 0);
    std::cout << "\nTest 5% tax on deposit\n";
    std::cout << "Initial liquidity is 1000 and 1000 more from openings and deposits\n";
    {
        Bank united_bank_of_money(1000);
        std::cout << united_bank_of_money;
        int acc = united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        int acc2 = united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        united_bank_of_money.deposit(acc, 100);
        std::cout << united_bank_of_money;
        united_bank_of_money.deposit(acc, 200);
        std::cout << united_bank_of_money;
        united_bank_of_money.deposit(acc2, 500);
        std::cout << united_bank_of_money;
        united_bank_of_money.close_account(acc);
        united_bank_of_money.close_account(acc2);
    }
    std::cout << "!!!CHANGE get_valid_id TO ONLY ALLOW FOR 10 ACCOUNTS FOR THIS TO WORK!!!\n";
    std::cout << "\nTest opening too many accounts\n";
    {
        Bank united_bank_of_money(1000);
        for (int i = 0; i < 11; i++)
            united_bank_of_money.open_account(100);
        for (int i = 0; i < 10; i++)
            united_bank_of_money.close_account(i);
    }
    std::cout << "\nTest opening accounts after some have been closed\n";
    {
        Bank united_bank_of_money(1000);
        std::cout << united_bank_of_money;
        int acc1 = united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        int acc2 = united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        int acc3 = united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        united_bank_of_money.close_account(acc1);
        std::cout << united_bank_of_money;
        united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        united_bank_of_money.close_account(acc2);
        std::cout << united_bank_of_money;
        united_bank_of_money.close_account(acc3);
        std::cout << united_bank_of_money;
        united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
        united_bank_of_money.open_account(100);
        std::cout << united_bank_of_money;
    }
    std::cout << "\nJust to see red\n";
    {
        Bank united_bank_of_money(1000);
        std::cout << united_bank_of_money;
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.loan(acc, 1000);
        united_bank_of_money.close_account(acc);
        std::cout << united_bank_of_money;
    }
    return 0;
}
