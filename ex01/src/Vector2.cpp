/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:44:05 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/25 15:11:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

Graph::Vector2::Vector2()
  : _x(0), _y(0) {}

Graph::Vector2::Vector2(float x, float y)
  : _x(x), _y(y) {}

Graph::Vector2::Vector2(const Vector2 &copy)
  : _x(copy._x), _y(copy._y) {}
  
Graph::Vector2 &Graph::Vector2::operator=(const Vector2 &copy) {
  if (this != &copy) {
    _x = copy._x;
    _y = copy._y;
  }
  return *this;
}

bool Graph::Vector2::operator==(const Vector2 &other) const {
  return _x == other._x && _y == other._y;
}

Graph::Vector2::~Vector2() {}

const float &Graph::Vector2::getX() const {
  return _x;
}

const float &Graph::Vector2::getY() const {
  return _y;
}
