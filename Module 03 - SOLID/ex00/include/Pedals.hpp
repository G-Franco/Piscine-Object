/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pedals.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:22:16 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 11:09:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define MAX_BRAKE_FORCE 100

class Pedals {
  private:
    int _speed;
    
    Pedals(const Pedals &copy);
    Pedals &operator=(const Pedals &copy);

  public:
    Pedals();
    ~Pedals();
    void accelerate(int speed);
    void brake(int force);
    int get_speed() const;
};
