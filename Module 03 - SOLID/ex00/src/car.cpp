/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:43:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 18:51:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/car.hpp"

Car::Car()
  : _engine(),
    _pedals(),
    _gearbox(),
    _steering() {}

Car::Car(const Car &copy)
  : _engine(),
    _pedals(),
    _gearbox(),
    _steering() {
  *this = copy;
}

Car &Car::operator=(const Car &copy) {
  (void)copy;
  return *this;
}

Car::~Car() {}

void Car::start() {
  if (_gearbox.get_gear() != 0) {
    std::cout << "Gear is not in neutral\n";
    return;
  }
  _engine.start();
  std::cout << "Engine is now on\n";
}

void Car::stop() {
  _engine.stop();
  _pedals.brake(MAX_BRAKE_FORCE);
  _pedals.accelerate(0);
  std::cout << "Engine is now off\n";
}

void Car::accelerate(int speed) {
  if (_engine.get_engine_state() == false) {
    std::cout << "Engine is off\n";
    return;
  }
  const int gear_max_speed = gear_speed[_gearbox.get_gear()];
  const int test_speed = _pedals.get_speed() + speed;
  if (gear_max_speed < test_speed) {
    std::cout << "Speed is too high for current gear ("
              << _gearbox.get_gear() << ")\n"
              << "Speed will be set to " << gear_max_speed << "\n";
    _pedals.accelerate(gear_max_speed);
    return;
  }
  _pedals.accelerate(test_speed);
}

void Car::shift_gears_up() {
  _gearbox.gear_up();
}

void Car::shift_gears_down() {
  _gearbox.gear_down();
  accelerate(_pedals.get_speed());
}

void Car::reverse() {
  _gearbox.reverse();
}

void Car::turn_wheel(int angle) {
  _steering.turn_wheel(angle);
}

void Car::straighten_wheels() {
  _steering.turn_wheel(0);
}

void Car::apply_force_on_brakes(int force) {
  _pedals.brake(force);
}

void Car::apply_emergency_brakes() {
  std::cout << "Emergency brakes applied\n";
  _pedals.brake(MAX_BRAKE_FORCE);
  _pedals.accelerate(0);
}
