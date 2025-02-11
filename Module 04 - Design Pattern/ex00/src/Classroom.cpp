/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:20:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Classroom.hpp"

Classroom::Classroom()
  : Room(),
    _course(NULL) {}

Classroom::Classroom(const Classroom &copy) 
  : Room(copy),
    _course(copy._course) {}

Classroom &Classroom::operator=(const Classroom &copy) {
  _course = copy._course;
  return *this;
}

Classroom::~Classroom() {}

void Classroom::assignCourse(Course* p_course) {
  // Allows null assignment to remove course
  _course = p_course;
}

Course* Classroom::getCourse() const {
  return _course;
}
