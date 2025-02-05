/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:50:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:17:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/triangle.hpp"

Triangle::Triangle()
  : Shape(),
    _side1(0),
    _side2(0),
    _side3(0) {}

Triangle::Triangle(int side1, int side2, int side3)
  : Shape(),
    _side1(side1),
    _side2(side2),
    _side3(side3) {
  if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
    throw std::runtime_error("Invalid triangle sides\n");
  }
}

Triangle::Triangle(const Triangle &copy)
  : Shape() {
  *this = copy;
}

Triangle &Triangle::operator=(const Triangle &copy) {
  _side1 = copy._side1;
  _side2 = copy._side2;
  _side3 = copy._side3;
  return *this;
}

Triangle::~Triangle() {}

double Triangle::area() const {
  double s = perimeter() / 2;
  return sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
}

double Triangle::perimeter() const {
  return _side1 + _side2 + _side3;
}