/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:40:09 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 11:45:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Tool.hpp"

class Hammer : public Tool {
  public:
    Hammer();
    Hammer(int uses);
    Hammer(const Hammer &copy);
    Hammer &operator=(const Hammer &copy);
    ~Hammer();
    void use();
    std::string get_type() const;
};
