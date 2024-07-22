/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:54 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/22 17:10:48 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Bank.hpp"

// TODO - Review liquidity and 5% tax

// Adjusted main case using subject values
int main()
{
    Bank too_big_to_fail(999);
    int account_A = too_big_to_fail.open_account(100);
    int account_B = too_big_to_fail.open_account(100);

    too_big_to_fail.invest_in_crypto(200);
    too_big_to_fail.deposit(account_A, 400);

    std::cout << "Account : " << "\n";
    std::cout << "accountA: ";
    too_big_to_fail.print_account_info(account_A);
    std::cout << "accountB: ";
    too_big_to_fail.print_account_info(account_B);

    std::cout << " ----- " << "\n";

    std::cout << "Bank : " << "\n";
    std::cout << too_big_to_fail << "\n";

    return (0);
}
