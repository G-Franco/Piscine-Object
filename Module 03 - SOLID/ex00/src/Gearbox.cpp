/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gearbox.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:52:49 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 12:08:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Gearbox.hpp"

Gearbox::Gearbox()
  : _gear(0) {}

Gearbox::Gearbox(const Gearbox &copy) {
  *this = copy;
}

Gearbox &Gearbox::operator=(const Gearbox &copy) {
  (void)copy;
  _gear = 0;
  return *this;
}

Gearbox::~Gearbox() {}

void Gearbox::gear_up() {
  if (_gear == MAX_GEAR) {
    std::cout << "Gear is already at maximum\n";
    return;
  }
  if (_gear == 6) {
    _gear = 0;
  }
  _gear++;
  std::cout << "Current gear: " << _gear << "\n";
}

void Gearbox::gear_down() {
  if (_gear == 0) {
    std::cout << "Gear is already at Neutral\n";
    return;
  }
  if (_gear == 6) {
    _gear = 2;
  }
  _gear--;
  std::cout << "Current gear: " << _gear << "\n";
}


void Gearbox::reverse() {
  _gear = 6;
  std::cout << "Current gear: R\n";
}

int Gearbox::get_gear() const {
  return _gear;
}
