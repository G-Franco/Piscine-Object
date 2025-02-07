/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:04:03 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/07 15:02:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circle.hpp"
#include "../include/rectangle.hpp"
#include "../include/triangle.hpp"

int main() {
  Shape *circle_base = new Circle(5);
  Circle *circle_derived = new Circle(5);
  Shape *rectangle_base = new Rectangle(5, 10);
  Rectangle *rectangle_derived = new Rectangle(5, 10);
  Shape *triangle_base = new Triangle(5, 5, 5);
  Triangle *triangle_derived = new Triangle(5, 5, 5);

  std::cout << "Circle_base area: " << circle_base->area() << "\n";
  std::cout << "Circle_base perimeter: " << circle_base->perimeter() << "\n";
  std::cout << "Circle_derived area: " << circle_base->area() << "\n";
  std::cout << "Circle_derived perimeter: " << circle_base->perimeter() << "\n";
  std::cout << "\nRectangle_base area: " << rectangle_base->area() << "\n";
  std::cout << "Rectangle_base perimeter: " << rectangle_base->perimeter() << "\n";
  std::cout << "Rectangle_derived area: " << rectangle_base->area() << "\n";
  std::cout << "Rectangle_derived perimeter: " << rectangle_base->perimeter() << "\n";
  std::cout << "\nTriangle_base area: " << triangle_base->area() << "\n";
  std::cout << "Triangle_base perimeter: " << triangle_base->perimeter() << "\n";
  std::cout << "Triangle_derived area: " << triangle_base->area() << "\n";
  std::cout << "Triangle_derived perimeter: " << triangle_base->perimeter() << "\n";
  delete circle_base;
  delete rectangle_base;
  delete triangle_base;
  delete circle_derived;
  delete rectangle_derived;
  delete triangle_derived;
}
