/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pedals.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:43:20 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 11:59:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Pedals.hpp"

Pedals::Pedals()
  : _speed(0) {}

Pedals::Pedals(const Pedals &copy) {
  *this = copy;
}

Pedals &Pedals::operator=(const Pedals &copy) {
  (void)copy;
  _speed = 0;
  return *this;
}

Pedals::~Pedals() {}

void Pedals::accelerate(int speed) {
  if (speed < 0) {
    speed = 0;
  }
  _speed += speed;
  std::cout << "Speed is now: " << _speed << "\n";
}

void Pedals::brake(int force) {
  if (force < 0) {
    force = 0;
  }
  std::cout << "Force applied: "
            << (force > MAX_BRAKE_FORCE ? MAX_BRAKE_FORCE : force) << "\n";
  _speed /= force;
  std::cout << "Speed is now: " << _speed << "\n";
}

int Pedals::get_speed() const {
  return _speed;
}
