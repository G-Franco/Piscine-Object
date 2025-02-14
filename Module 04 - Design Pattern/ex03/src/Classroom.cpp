/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:34:03 by gacorrei         ###   ########.fr       */
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
  _id = copy._id;
  _course = copy._course;
  return *this;
}

bool Classroom::operator==(const Classroom &other) const {
  return _id == other._id;
}

Classroom::~Classroom() {}

void Classroom::assignCourse(Course* p_course) {
  // Allows null assignment to remove course
  _course = p_course;
}

Course* Classroom::getCourse() const {
  return _course;
}
