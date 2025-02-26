/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 11:52:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Classroom.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"

Classroom::Classroom()
  : Room(),
    _course(std::weak_ptr<Course>()) {}

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
// For comparisons between weak ptrs, using owner_before is used since
// it is the only way to compare weak ptrs correctly (even if they are expired)
// This operation checks if a pointer is ordered before another,
// if it is, then the control block of the first pointer is not the same
// as the control block of the second pointer
bool Classroom::canEnter(std::weak_ptr<Person> person) {
  if (person.expired()) {
    return false;
  }
  auto person_ptr = person.lock();
  bool same_course = !person_ptr->room().owner_before(_course) &&
                      !_course.owner_before(person_ptr->room());
  if (auto professor = std::dynamic_pointer_cast<Professor>(person_ptr)) {
    if (!_occupants.empty() || !same_course) {
      return false;
    }
    return true;
  }
  if (auto student = std::dynamic_pointer_cast<Student>(person_ptr)) {
    if (_occupants.empty() ||
        !student->is_subscribed(_course)) {
      return false;
    }
    return true;
  }
  return false;
}

// Allows null assignment to remove course
void Classroom::assignCourse(std::weak_ptr<Course> course) {
  _course = course;
}

std::weak_ptr<Course> Classroom::getCourse() const {
  return _course;
}
