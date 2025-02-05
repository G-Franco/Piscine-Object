/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:10:08 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "shape.hpp"
#include <iostream>

class Triangle : public Shape {
  private:
    int _side1;
    int _side2;
    int _side3;

    Triangle();

  public:
    Triangle(int side1, int side2, int side3);
    Triangle(const Triangle &copy);
    Triangle &operator=(const Triangle &copy);
    ~Triangle();
    double area() const;
    double perimeter() const;
};
