/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:01:31 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 18:59:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/car.hpp"

int main() {
  Car lada;

  lada.shift_gears_up();
  lada.start();
  lada.shift_gears_down();
  lada.start();
  lada.start();
  lada.accelerate(50);
  lada.reverse();
  lada.accelerate(50);
  lada.accelerate(-10);
  lada.shift_gears_up();
  lada.apply_force_on_brakes(50);
  lada.accelerate(25);
  lada.accelerate(10);
  lada.shift_gears_up();
  lada.accelerate(10);
  lada.shift_gears_down();
  lada.accelerate(-15);
  lada.shift_gears_down();
  lada.accelerate(300);
  lada.shift_gears_up();
  lada.accelerate(300);
  lada.shift_gears_up();
  lada.accelerate(300);
  lada.shift_gears_up();
  lada.accelerate(300);
  lada.shift_gears_up();
  lada.accelerate(300);
  lada.shift_gears_up();
  lada.accelerate(300);
  lada.shift_gears_up();
  lada.accelerate(300);
  lada.turn_wheel(300);
  lada.turn_wheel(3000);
  lada.turn_wheel(-500);
  lada.shift_gears_down();
  lada.shift_gears_down();
  lada.shift_gears_down();
  lada.shift_gears_down();
  lada.shift_gears_down();
  lada.apply_emergency_brakes();
  lada.stop();
  lada.stop();
}
