/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:11:58 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 14:54:53 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Student.hpp"

Student::Student(std::string name)
  : Person(name) {}

Student::Student(const Student &copy)
  : Person(copy),
    _subscribedCourse(copy._subscribedCourse) {}

Student &Student::operator=(const Student &copy) {
  _subscribedCourse = copy._subscribedCourse;
  return *this;
}

bool Student::operator==(const Student &other) const {
  return _name == other._name;
}

Student::~Student() {}

void Student::attendClass(Classroom* p_classroom) {
  if (!p_classroom) {
    std::cout << "[ATTEND CLASS] Classroom is null\n";
    return;
  }
  if (p_classroom->enter(this)) {
    std::cout << _name << " is attending class in "
              << p_classroom->getCourse()->get_name() << "\n";
  }
  else {
    std::cout << _name << " cannot attend class in "
              << p_classroom->getCourse()->get_name() << "\n";
  }
}

void Student::exitClass() {
  if (!_currentRoom) {
    std::cout << "[EXIT CLASS] Student is not in a classroom\n";
    return;
  }
  _currentRoom->exit(this);
  std::cout << _name << " exited class\n";
}

void Student::graduate(Course* p_course) {
  if (!p_course) {
    std::cout << "[GRADUATE] Course is null\n";
    return;
  }
  // Implement when there is info
}
