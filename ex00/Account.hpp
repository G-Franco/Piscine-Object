/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:16:39 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/08 14:09:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Account
{
    private:
        int id;
        long long value;
        Account();
        Account(const Account &copy);
    public:
        Account(int id, long long value);
        Account &operator=(const Account &copy);
        bool operator==(int test) const;
        ~Account();
        const int &get_id() const;
        const long long &get_value() const;
        void deposit(long long amount);
        void withdrawal(long long amount);
};

std::ostream &operator<<(std::ostream &out, const Account &account);
