/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:09:21 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 11:45:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Tool.hpp"

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