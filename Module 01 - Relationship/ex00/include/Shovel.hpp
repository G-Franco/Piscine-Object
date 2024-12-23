/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:09:21 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/16 11:09:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../include/Tool.hpp"

class Shovel : public Tool {
  public:
    Shovel();
    Shovel(int uses);
    Shovel(const Shovel &copy);
    Shovel &operator=(const Shovel &copy);
    ~Shovel();
    void use();
    std::string get_type() const;
};