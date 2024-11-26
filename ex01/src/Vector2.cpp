/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:44:05 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/26 11:21:48 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

Graph::Vector2::Vector2()
  : _x(0),
    _y(0),
    _nearest_x(0),
    _nearest_y(0) {}

Graph::Vector2::Vector2(float x, float y)
  : _x(x),
    _y(y),
    _nearest_x(static_cast<int>(std::floor(x + 0.5))),
    _nearest_y(static_cast<int>(std::floor(y + 0.5))) {}

Graph::Vector2::Vector2(const Vector2 &copy)
  : _x(copy._x),
    _y(copy._y),
    _nearest_x(copy._nearest_x),
    _nearest_y(copy._nearest_y) {}
  
Graph::Vector2 &Graph::Vector2::operator=(const Vector2 &copy) {
  if (this != &copy) {
    _x = copy._x;
    _y = copy._y;
    _nearest_x = copy._nearest_x;
    _nearest_y = copy._nearest_y;
  }
  return *this;
}

// Need to compare the nearest coordinates.
// Otherwise similar points (floats only) will end up in the same
// grid coordinates but will not be considered equal
bool Graph::Vector2::operator==(const Vector2 &other) const {
  return _nearest_x == other._nearest_x && _nearest_y == other._nearest_y;
}

Graph::Vector2::~Vector2() {}

const float &Graph::Vector2::getX() const {
  return _x;
}

const float &Graph::Vector2::getY() const {
  return _y;
}

const int &Graph::Vector2::get_nearest_X() const {
  return _nearest_x;
}

const int &Graph::Vector2::get_nearest_Y() const {
  return _nearest_y;
}
