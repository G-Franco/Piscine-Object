/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:54 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/25 16:07:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Bank.hpp"

// TODO - fix using negative values for unsigned long cases
// TODO - make messages for account opening and depositing more clear
// TODO - Check account id's after fixing above issues

// Adjusted main case using subject values
// int main()
// {
//     Bank too_big_to_fail(999);
//     int account_A = too_big_to_fail.open_account(100);
//     int account_B = too_big_to_fail.open_account(100);

//     too_big_to_fail.invest_in_crypto(200);
//     too_big_to_fail.deposit(account_A, 400);

//     std::cout << "Accounts: " << "\n";
//     std::cout << "accountA: ";
//     too_big_to_fail.print_account_info(account_A);
//     std::cout << "accountB: ";
//     too_big_to_fail.print_account_info(account_B);

//     std::cout << " ----- " << "\n";

//     std::cout << "Bank: " << "\n";
//     std::cout << too_big_to_fail;

//     return 0;
// }

// My main
int main()
{
    std::cout << "Test bank creation with default constructor\n";
    {
        Bank united_bank_of_money;
        std::cout << united_bank_of_money;
    }
    std::cout << "\nTest bank creation with negative initial liquidity\n";
    {
        Bank united_bank_of_money(-1000);
        std::cout << united_bank_of_money;
    }
    std::cout << "\nTest bank creation with 0 initial liquidity\n";
    {
        Bank united_bank_of_money(0);
        std::cout << united_bank_of_money;
    }
    std::cout << "\nTest bank creation with positive initial liquidity\n";
    Bank united_bank_of_money(1000);
    std::cout << united_bank_of_money;
    std::cout << "\nTest account creation with less than 100 initial value\n";
    {
        united_bank_of_money.open_account(50);
        std::cout << united_bank_of_money;
    }
    std::cout << "\nTest account creation with negative initial value\n";
    {
        united_bank_of_money.open_account(-100);
    }
    std::cout << "\nTest account creation with 0 initial value\n";
    {
        united_bank_of_money.open_account(0);
    }
    std::cout << "\nTest account creation with positive initial value\n";
    {
        united_bank_of_money.open_account(100);
        united_bank_of_money.close_account(0);
    }
    std::cout << "\nTest closing account with wrong positive id\n";
    {
        united_bank_of_money.open_account(100);
        united_bank_of_money.close_account(1);
    }
    std::cout << "\nTest closing account with wrong negative id\n";
    {
        united_bank_of_money.open_account(100);
        united_bank_of_money.close_account(-1);
    }
    std::cout << "\nTest deposit with positive amount\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.deposit(acc, 100);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest deposit with negative amount\n";    
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.deposit(acc, -100);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest deposit with 0 amount\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.deposit(acc, 0);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest deposit with positive amount less than 10\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.deposit(acc, 9);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest withdrawal with positive amount\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.withdrawal(acc, 50);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest withdrawal with negative amount\n";    
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.withdrawal(acc, -100);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest withdrawal with 0 amount\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.withdrawal(acc, 0);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest withdrawal with positive amount greater than account value\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.withdrawal(acc, 200);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest loan with positive amount\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.loan(acc, 100);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest loan with negative amount\n";    
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.loan(acc, -100);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest loan with 0 amount\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.loan(acc, 0);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest loan with positive amount greater than bank liquidity\n";
    {
        int acc = united_bank_of_money.open_account(100);
        united_bank_of_money.loan(acc, 2000);
        united_bank_of_money.close_account(acc);
    }
    std::cout << "\nTest inflation machine with positive amount\n";
    {
        united_bank_of_money.inflation_machine(100);
    }
    std::cout << "\nTest inflation machine with negative amount\n";    
    {
        united_bank_of_money.inflation_machine(-100);
    }
    std::cout << "\nTest inflation machine with 0 amount\n";
    {
        united_bank_of_money.inflation_machine(0);
    }
    std::cout << "\nTest inflation machine with positive amount less than 100\n";
    {
        united_bank_of_money.inflation_machine(99);
    }
    std::cout << "\nTest invest in crypto with positive amount\n";
    {
        united_bank_of_money.invest_in_crypto(100);
    }
    std::cout << "\nTest invest in crypto with negative amount\n";    
    {
        united_bank_of_money.invest_in_crypto(-100);
    }
    std::cout << "\nTest invest in crypto with 0 amount\n";
    {
        united_bank_of_money.invest_in_crypto(0);
    }
    std::cout << "\nTest 5% tax on deposit\n";
    std::cout << "Initial liquidity is 1000 and 1000 more from openings and deposits\n";
    {
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
        for (int i = 0; i < 11; i++)
            united_bank_of_money.open_account(100);
        for (int i = 0; i < 10; i++)
            united_bank_of_money.close_account(i);
    }
    std::cout << "\nTest opening accounts after some have been closed\n";
    {
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
    return 0;
}
