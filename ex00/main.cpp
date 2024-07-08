/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:54 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/08 11:19:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Bank.hpp"

int main()
{
    Account accountA = Account();
    accountA.id = 0;
    accountA.value = 100;

    Account accountB = Account();
    accountB.id = 1;
    accountB.value = 100;

    Bank bank = Bank();
    bank.liquidity = 999;
    bank.clientAccounts.push_back(&accountA);
    bank.clientAccounts.push_back(&accountB);

    bank.liquidity -= 200;
    accountA.value += 400;

    std::cout << "Account : " << std::endl;
    std::cout << accountA << std::endl;
    std::cout << accountB << std::endl;

    std::cout << " ----- " << std::endl;

    std::cout << "Bank : " << std::endl;
    std::cout << bank << std::endl;

    return (0);
}