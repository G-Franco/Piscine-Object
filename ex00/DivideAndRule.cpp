/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideAndRule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:08:46 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/22 17:03:36 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TOD - The bank must receive 5 % of each money inflow on these client accounts
// TOD - The accounts must never have two identical IDs
// TOD - The attributes of the structures must not be modifiable from the outside
// TOD - The bank must be able to create, delete and modify the accounts of these customers
// TOD - The bank must be able to give a loan to a customer, within the limits of its funds
// TOD - It must be impossible to add money to a client account without going through the bank
// TOD - If it makes sense, the creation of a Getter and a Setter is mandatory.Getter(s) by copy will not be accepted
// TOD - If it makes sense, the creation of a const Getter is mandatory.const Getter(s) by copy will not be accepted
#include <iostream>
#include <vector>

struct Account
{
    int id;
    int value;

    Account() : id(-1),
                value(0)
    {
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
    {
        p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
        return (p_os);
    }
};

struct Bank
{
    int liquidity;
    std::vector<Account *> clientAccounts;

    Bank() : liquidity(0)
    {
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
    {
        p_os << "Bank informations : " << "\n";
        p_os << "Liquidity : " << p_bank.liquidity << "\n";
        for (auto &clientAccount : p_bank.clientAccounts)
            p_os << *clientAccount << "\n";
        return (p_os);
    }
};
