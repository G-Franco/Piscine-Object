/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:39:17 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:06:48 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "shape.hpp"

class Rectangle : public Shape {
  private:
    int _width;
    int _height;

    Rectangle();

  public:
    Rectangle(int width, int height);
    Rectangle(const Rectangle &copy);
    Rectangle &operator=(const Rectangle &copy);
    ~Rectangle();
    double area() const;
    double perimeter() const;
};
