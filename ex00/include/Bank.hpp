/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:19 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/01 15:47:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include "Account.hpp"

class Bank {
  private:
    long long _liquidity;
    std::vector<Account> _accounts;

    Bank();
    Bank(const Bank &copy);
    Bank &operator=(const Bank &copy);

  public:
    Bank(long long liquidity);
    ~Bank();
    std::string get_bank_info() const;
};

std::ostream &operator<<(std::ostream &out, const Bank &bank);
