/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:11:58 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/19 16:50:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Student.hpp"

Student::Student(std::string name, Headmaster &headmaster)
  : Person(name),
    _headmaster(headmaster) {}

Student::Student(const Student &copy)
  : Person(copy),
    _subscribedCourses(copy._subscribedCourses),
    _headmaster(copy._headmaster) {}

Student &Student::operator=(const Student &copy) {
  _subscribedCourses = copy._subscribedCourses;
  _headmaster = copy._headmaster;
  return *this;
}

bool Student::operator==(const Student &other) const {
  return _name == other._name;
}

bool Student::operator==(const std::string name) const {
  return _name == name;
}

Student::~Student() {}

void Student::choose_class(std::string course_name) {
  if (course_name.empty()) {
    std::cout << "[CHOOSE CLASS] Choose a valid course name\n";
    return;
  }
  _headmaster.request(*this, FormType::SubscriptionToCourse, course_name);
}

bool Student::subscribe(Course* course) {
  if (!course) {
    std::cout << "[SUBSCRIBE] Course is null\n";
    return false;
  }
  if (std::find(_subscribedCourses.begin(), _subscribedCourses.end(), course) != _subscribedCourses.end()) {
    std::cout << _name << " is already subscribed to " << course->get_name() << "\n";
    return false;
  }
  if (!course->check_student(this)) {
    std::cout << _name << " cannot subscribe to " << course->get_name() << "\n";
    return false;
  }
  _subscribedCourses.push_back(course);
  std::cout << _name << " subscribed to " << course->get_name() << "\n";
  return true;
}

void Student::unsubscribe(Course* course) {
  if (!course) {
    std::cout << "[UNSUBSCRIBE] Course is null\n";
    return;
  }
  auto it = std::find(_subscribedCourses.begin(), _subscribedCourses.end(), course);
  if (it == _subscribedCourses.end()) {
    std::cout << _name << " is not subscribed to " << course->get_name() << "\n";
    return;
  }
  _subscribedCourses.erase(it);
  std::cout << _name << " unsubscribed from " << course->get_name() << "\n";
}

void Student::attendClass(Classroom* p_classroom) {
  if (!p_classroom) {
    std::cout << "[ATTEND CLASS] Classroom is null\n";
    return;
  }
  if (std::find(_subscribedCourses.begin(), _subscribedCourses.end(), p_classroom->getCourse()) == _subscribedCourses.end()) {
    std::cout << _name << " is not subscribed to " << p_classroom->getCourse()->get_name() << "\n";
    return;
  }
  if (p_classroom->enter(this)) {
    std::cout << _name << " is attending class in "
              << p_classroom->getCourse()->get_name() << "\n";
    p_classroom->getCourse()->class_attendance(this);
  }
  else {
    std::cout << _name << " cannot attend class in "
              << p_classroom->getCourse()->get_name() 
              << ", there is no room\n";
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
  unsubscribe(p_course);
  std::cout << _name << ": I graduated from " << p_course->get_name() << "!\n";
}

bool Student::is_subscribed(Course* course) {
  if (!course) {
    std::cout << "[IS SUBSCRIBED] Course is null\n";
    return false;
  }
  if (std::find(_subscribedCourses.begin(), _subscribedCourses.end(), course) != _subscribedCourses.end()) {
    return true;
  }
  return false;
}
