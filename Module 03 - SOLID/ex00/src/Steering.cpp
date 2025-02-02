/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Steering.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:55:14 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 12:09:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Steering.hpp"

Steering::Steering()
  : _angle(0) {}

Steering::Steering(const Steering &copy) {
  *this = copy;
}

Steering &Steering::operator=(const Steering &copy) {
  (void)copy;
  _angle = 0;
  return *this;
}

Steering::~Steering() {}

void Steering::turn_wheel(int angle) {
  int new_angle = _angle + angle;
  if (abs(new_angle) > MAX_STEER_ANGLE) {
    _angle = (new_angle > 0 ? MAX_STEER_ANGLE : -MAX_STEER_ANGLE);
    std::cout << "Angle is too high\n"
              << "Angle will be set to " << _angle << "\n";
    return;
  }
  _angle = new_angle;
  std::cout << "Steering wheel angle: " << _angle << "\n";
}
