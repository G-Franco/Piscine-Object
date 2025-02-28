/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:33:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/28 11:47:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Professor.hpp"
#include "../include/Headmaster.hpp"
#include "../include/Course.hpp"
#include "../include/Form.hpp"

Professor::Professor(std::string name)
  : Staff(name),
    _currentCourse(std::weak_ptr<Course>()) {}

Professor::Professor(const Professor &copy)
  : Staff(copy),
    _currentCourse(copy._currentCourse) {}

Professor &Professor::operator=(const Professor &copy) {
  _currentCourse = copy._currentCourse;
  return *this;
}

bool Professor::operator==(const Professor &other) const {
  return get_name() == other.get_name();
}

bool Professor::operator==(const std::string name) const {
  return get_name() == name;
}

Professor::~Professor() {}

void Professor::set_self(std::weak_ptr<Professor> self) {
  if (self.expired()) {
    std::cout << "[SET SELF] Self pointer is empty\n";
    return;
  }
  _self = self;
}

void Professor::request_course(std::string course_name) {
  if (course_name.empty()) {
    std::cout << "[REQUEST COURSE] Course name is empty\n";
    return;
  }
  if (auto self = _self.lock()) {
    std::weak_ptr<Person> p_self = _self;
    _headmaster->request(p_self, FormType::NeedCourseCreation, course_name);
  }
  else {
    std::cout << "[REQUEST COURSE] Professor needs to have a self pointer assigned\n";
  }
}

void Professor::request_graduation(std::weak_ptr<Student> &student) {
  if (_currentCourse.expired()) {
    std::cout << "[REQUEST GRADUATION] Course not assigned\n";
    return;
  }
  if (student.expired()) {
    std::cout << "[REQUEST GRADUATION] Student is empty\n";
    return;
  }
  auto stud = student.lock();
  auto course = _currentCourse.lock();
  if (!stud->is_subscribed(_currentCourse)) {
    std::cout << stud->get_name() << " is not subscribed to " << course->get_name() << "\n";
    return;
  }
  if (auto self = _self.lock()) {
    std::weak_ptr<Person> p_self = _self;
    _headmaster->request(p_self, FormType::CourseFinished, stud->get_name());
  }
  else {
    std::cout << "[REQUEST GRADUATION] Professor needs a self pointer assigned\n";
  }
}

void Professor::assignCourse(std::weak_ptr<Course> &course) {
  _currentCourse = course;
}

void Professor::doClass() {
  if (_currentCourse.expired()) {
    std::cout << "[DO CLASS] Course is null\n";
    return;
  }
  if (_self.expired()) {
    std::cout << "[DO CLASS] Professor needs a self pointer assigned\n";
    return;
  } 
  std::weak_ptr<Person> self = _self;
  auto course = _currentCourse.lock();
  std::weak_ptr<Classroom> classroom = course->get_empty_classroom();
  if (classroom.expired()) {
    std::cout << "No classroom available for " << course->get_name() << "\n";
    _headmaster->request(self, FormType::NeedMoreClassRoom, "");
    classroom = course->get_empty_classroom();
  }
  auto c_room = classroom.lock();
  if (c_room->enter(self)) {
    std::cout << "Professor will hold class: " << course->get_name() << "\n";
  }
}

void Professor::closeCourse() {
  if (_currentCourse.expired()) {
    std::cout << "[DO CLASS] Course is null\n";
    return;
  }
  auto course = _currentCourse.lock();
  std::cout << "Professor closed course: " << course->get_name() << "\n";
  _currentCourse = std::weak_ptr<Course>();
}

std::weak_ptr<Course> Professor::get_current_course() const {
  return _currentCourse;
}
