/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:27 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/01 16:07:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>

class Account {
  private:
    unsigned int _id;
    int _value;

    Account();

  public:
    Account(int id, long long value);
    Account(const Account &copy);
    Account &operator=(const Account &copy);
    ~Account();
    std::string get_account_info() const;
};

std::ostream &operator<<(std::ostream &out, const Account &account);
