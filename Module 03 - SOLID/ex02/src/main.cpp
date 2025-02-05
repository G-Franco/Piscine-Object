/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:04:03 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:11:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circle.hpp"
#include "../include/rectangle.hpp"
#include "../include/triangle.hpp"

int main() {
  Shape *circle = new Circle(5);
  Shape *rectangle = new Rectangle(5, 10);
  Shape *triangle = new Triangle(5, 5, 5);

  std::cout << "Circle area: " << circle->area() << "\n";
  std::cout << "Circle perimeter: " << circle->perimeter() << "\n";
  std::cout << "\nRectangle area: " << rectangle->area() << "\n";
  std::cout << "Rectangle perimeter: " << rectangle->perimeter() << "\n";
  std::cout << "\nTriangle area: " << triangle->area() << "\n";
  std::cout << "Triangle perimeter: " << triangle->perimeter() << "\n";
  delete circle;
  delete rectangle;
  delete triangle;
}
