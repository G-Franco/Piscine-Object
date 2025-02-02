/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gearbox.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:22:14 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 10:26:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define MAX_GEAR 5

class Gearbox {
  private:
    int _gear;
    
    Gearbox(const Gearbox &copy);
    Gearbox &operator=(const Gearbox &copy);

  public:
    Gearbox();
    ~Gearbox();
    void gear_up();
    void gear_down();
    void reverse();
    int get_gear() const;
};
