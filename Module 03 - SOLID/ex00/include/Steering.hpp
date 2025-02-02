/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Steering.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:22:17 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/01 11:55:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

#define MAX_STEER_ANGLE 1080

class Steering {
  private:
    int _angle;
    
    Steering(const Steering &copy);
    Steering &operator=(const Steering &copy);

  public:
    Steering();
    ~Steering();
    void turn_wheel(int angle);
};
