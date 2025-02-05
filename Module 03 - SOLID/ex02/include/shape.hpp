/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:34:06 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:00:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <stdexcept>

class Shape {
public:
  Shape();
  Shape(const Shape &copy);
  Shape &operator=(const Shape &copy);
  virtual ~Shape();
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
};
