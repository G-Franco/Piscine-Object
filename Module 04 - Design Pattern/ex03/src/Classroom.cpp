/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 11:57:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Classroom.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"

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

// There can only be 1 professor in a classroom and that professor
// must be the one responsible for the course
// There can be multiple (enrolled) students in a classroom but they can only
// enter after the professor has entered
bool Classroom::canEnter(std::shared_ptr<Person> person) {
  if (auto professor = std::dynamic_pointer_cast<Professor>(person)) {
    if (!_occupants.empty() ||
        professor->get_current_course() != _course) {
      return false;
    }
    return true;
  }
  if (auto student = std::dynamic_pointer_cast<Student>(person)) {
    if (_occupants.empty() ||
        !student->is_subscribed(_course)) {
      return false;
    }
    return true;
  }
  return false;
}

// Allows null assignment to remove course
void Classroom::assignCourse(std::shared_ptr<Course> course) {
  _course = course;
}

std::shared_ptr<Course> Classroom::getCourse() const {
  return _course;
}
