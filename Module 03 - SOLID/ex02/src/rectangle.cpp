/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:41:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:17:08 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rectangle.hpp"

Rectangle::Rectangle()
  : Shape(),
    _width(0),
    _height(0) {}

Rectangle::Rectangle(int width, int height)
  : Shape(),
    _width(width),
    _height(height) {
  if (width <= 0 || height <= 0) {
    throw std::runtime_error("Invalid rectangle dimensions\n");
  }      
}

Rectangle::Rectangle(const Rectangle &copy)
  : Shape() {
  *this = copy;
}

Rectangle &Rectangle::operator=(const Rectangle &copy) {
  _width = copy._width;
  _height = copy._height;
  return *this;
}

Rectangle::~Rectangle() {}

double Rectangle::area() const {
  return _width * _height;
}

double Rectangle::perimeter() const {
  return 2 * (_width + _height);
}
