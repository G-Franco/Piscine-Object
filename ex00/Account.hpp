/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:16:39 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/29 16:02:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Account
{
    private:
        int _id;
        int _value;
        Account();
    
    public:
        Account(int id, int value);
        Account(const Account &copy);
        Account &operator=(const Account &copy);
        bool operator==(int test) const;
        ~Account();
        const int &get_id() const;
        const int &get_value() const;
        void deposit(int amount);
        void withdrawal(int amount);
};

std::ostream &operator<<(std::ostream &out, const Account &account);
