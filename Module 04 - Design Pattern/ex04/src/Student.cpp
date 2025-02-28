/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:11:58 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 12:11:53 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Student.hpp"
#include "../include/Headmaster.hpp"
#include "../include/Course.hpp"
#include "../include/Form.hpp"
#include "../include/helper.hpp"

Student::Student(std::string name)
  : Person(name) {}

Student::Student(const Student &copy)
  : Person(copy),
    _subscribedCourses(copy._subscribedCourses) {}

Student &Student::operator=(const Student &copy) {
  _subscribedCourses = copy._subscribedCourses;
  return *this;
}

bool Student::operator==(const Student &other) const {
  return _name == other._name;
}

bool Student::operator==(const std::string name) const {
  return _name == name;
}

Student::~Student() {}

void Student::set_self(std::weak_ptr<Student> self) {
  if (self.expired()) {
    std::cout << "[SET SELF] Self pointer is empty\n";
    return;
  }
  _self = self;
}

void Student::choose_class(std::string course_name) {
  if (course_name.empty()) {
    std::cout << "[CHOOSE CLASS] Choose a valid course name\n";
    return;
  }
  if (_self.expired()) {
    std::cout << "[CHOOSE CLASS] Student needs a self pointer assigned\n";
    return;
  }
  std::shared_ptr<Person> self = _self.lock();
  std::weak_ptr<Person> p_self = self;
  _headmaster->request(p_self, FormType::SubscriptionToCourse, course_name);
}

bool Student::subscribe(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[SUBSCRIBE] Course is null\n";
    return false;
  }
  auto crs = course.lock();
  if (weak_pointer_find(_subscribedCourses, course)) {
    std::cout << _name << " is already subscribed to " << crs->get_name() << "\n";
    return false;
  }
  if (_self.expired()) {
    std::cout << "[CHOOSE CLASS] Student needs a self pointer assigned\n";
    return false;
  }
  if (!crs->check_student(_self)) {
    std::cout << _name << " cannot subscribe to " << crs->get_name() << "\n";
    return false;
  }
  _subscribedCourses.push_back(course);
  std::cout << _name << " subscribed to " << crs->get_name() << "\n";
  return true;
}

void Student::unsubscribe(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[UNSUBSCRIBE] Course is null\n";
    return;
  }
  auto crs = course.lock();
  if (weak_pointer_erase(_subscribedCourses, course)) {
    std::cout << _name << " unsubscribed from " << crs->get_name() << "\n";
    return;
  }
  std::cout << _name << " is not subscribed to " << crs->get_name() << "\n";
}

void Student::attendClass(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[ATTEND CLASS] Course is null\n";
    return;
  }
  auto crs = course.lock();
  if (!weak_pointer_find(_subscribedCourses, course)) {
    std::cout << _name << " is not subscribed to " << crs->get_name() << "\n";
    return;
  }
  if (_self.expired()) {
    std::cout << "[ATTEND CLASS] Student needs a self pointer assigned\n";
    return;
  }
  std::shared_ptr<Person> self = _self.lock();
  std::weak_ptr<Person> p_self = self;
  for (auto classroom : crs->get_classrooms()) {
    if (classroom.expired()) {
      continue;
    }
    auto room = classroom.lock();
    if (room->enter(p_self)) {
      std::cout << _name << " is attending class in "
                << crs->get_name() << "\n";
      crs->class_attendance(_self);
      return;
    }
  }
  std::cout << _name << " cannot attend class for "
            << crs->get_name() << "\n";
}

void Student::exitClass() {
  if (_currentRoom.expired()) {
    std::cout << "[EXIT CLASS] Student is not in a classroom\n";
    return;
  }
  if (_self.expired()) {
    std::cout << "[EXIT CLASS] Student needs a self pointer assigned\n";
    return;
  }
  auto room = _currentRoom.lock();
  std::shared_ptr<Person> self = _self.lock();
  std::weak_ptr<Person> p_self = self;
  room->exit(p_self);
  std::cout << _name << " exited class\n";
}

void Student::graduate(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[GRADUATE] Course is null\n";
    return;
  }
  auto crs = course.lock();
  unsubscribe(course);
  std::cout << _name << ": I graduated from " << crs->get_name() << "!\n";
}

bool Student::is_subscribed(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[IS SUBSCRIBED] Course is null\n";
    return false;
  }
  if (weak_pointer_find(_subscribedCourses, course)) {
    return true;
  }
  return false;
}

std::vector<std::weak_ptr<Course>> Student::get_subscribed_courses() const {
  return _subscribedCourses;
}
