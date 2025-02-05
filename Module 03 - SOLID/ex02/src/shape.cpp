/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:13 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/05 15:20:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shape.hpp"

Shape::Shape() {}

// Since there are no member variables nothing needs to be copied
Shape::Shape(const Shape &copy) {
  (void)copy;
}

// Same as above
Shape &Shape::operator=(const Shape &copy) {
  (void)copy;
  return *this;
}

Shape::~Shape() {}