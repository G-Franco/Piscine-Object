/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:33:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 11:54:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Engine.hpp"
#include "Pedals.hpp"
#include "Gearbox.hpp"
#include "Steering.hpp"

enum gear_speed {
  NEUTRAL = 0,
  FIRST = 30,
  SECOND = 60,
  THIRD = 100,
  FOURTH = 150,
  FIFTH = 200,
  REVERSE = 20
};

class Car {
  private:
    Engine _engine;
    Pedals _pedals;
    Gearbox _gearbox;
    Steering _steering;
    Car(const Car &copy);
    Car &operator=(const Car &copy);

  public:
    Car();
    ~Car();
    void start();
    void stop();
    void accelerate(int speed);
    void apply_force_on_brakes(int force);
    void shift_gears_up();
    void shift_gears_down();
    void reverse();
    void turn_wheel(int angle);
    void straighten_wheels();
    void apply_emergency_brakes();
};
