/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:44:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:06:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "shape.hpp"

#define PI 3.14

class Circle : public Shape {
  private:
    int _radius;

    Circle();

  public:
    Circle(int radius);
    Circle(const Circle &copy);
    Circle &operator=(const Circle &copy);
    ~Circle();
    double area() const;
    double perimeter() const;
};
