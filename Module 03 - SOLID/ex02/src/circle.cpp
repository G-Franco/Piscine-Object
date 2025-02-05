/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:44:21 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:17:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circle.hpp"

Circle::Circle()
  : Shape(),
    _radius(0) {}

Circle::Circle(int radius)
  : Shape(),
    _radius(radius) {
  if (radius <= 0) {
    throw std::runtime_error("Invalid circle radius\n");
  }
}

Circle::Circle(const Circle &copy)
  : Shape() {
  *this = copy;
}

Circle &Circle::operator=(const Circle &copy) {
  _radius = copy._radius;
  return *this;
}

Circle::~Circle() {}

double Circle::area() const {
  return PI * _radius * _radius;
}

double Circle::perimeter() const {
  return 2 * PI * _radius;
}
