/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:33:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 15:42:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Professor.hpp"
#include "../include/Headmaster.hpp"
#include "../include/Course.hpp"
#include "../include/Form.hpp"
#include "../include/helper.hpp"

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

void Professor::request_course(std::string course_name) {
  if (course_name.empty()) {
    std::cout << "[REQUEST COURSE] Course name is empty\n";
    return;
  }
  if (_self.expired()) {
    std::cout << "[REQUEST COURSE] Professor needs to have a self pointer assigned\n";
    return;
  }
  _headmaster->request(_self, FormType::NeedCourseCreation, course_name);
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
  if (_self.expired()) {
    std::cout << "[REQUEST GRADUATION] Professor needs a self pointer assigned\n";
    return;
  }
  _headmaster->request(_self, FormType::CourseFinished, stud->get_name());
}

void Professor::assignCourse(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[ASSIGN COURSE] Course is null\n";
    return;
  }
  _currentCourse = course;
}

void Professor::closeCourse() {
  if (_currentCourse.expired()) {
    std::cout << "[DO CLASS] Course is null\n";
    return;
  }
  auto course = _currentCourse.lock();
  std::cout << "Professor closed course: " << course->get_name() << "\n";
  _currentCourse = std::weak_ptr<Course>();
  _graduation_requests.clear();
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
  auto course = _currentCourse.lock();
  std::weak_ptr<Classroom> classroom = course->get_empty_classroom();
  if (classroom.expired()) {
    std::cout << "No classroom available for " << course->get_name() << "\n";
    _headmaster->request(_self, FormType::NeedMoreClassRoom, "");
    classroom = course->get_empty_classroom();
  }
  auto c_room = classroom.lock();
  if (c_room->enter(_self)) {
    std::cout << "Professor will hold class: " << course->get_name() << "\n";
  }
}

void Professor::course_graduation_request(std::weak_ptr<Student> &student) {
  if (student.expired()) {
    std::cout << "[COURSE GRADUATION REQUEST] Student is empty\n";
    return;
  }
  if (weak_pointer_find(_graduation_requests, student)) {
    std::cout << "[COURSE GRADUATION REQUEST] Student already on list\n";
    return;
  }
  _graduation_requests.push_back(student);
}

void Professor::check_graduation_requests() {
  if (_currentCourse.expired()) {
    std::cout << "[CHECK GRADUATION REQUESTS] Course not assigned\n";
    return;
  }
  if (_self.expired()) {
    std::cout << "[CHECK GRADUATION REQUESTS] Professor needs a self pointer assigned\n";
    return;
  }
  for (const auto &student : _graduation_requests) {
    if (student.expired()) {
      continue;
    }
    _headmaster->request(_self, FormType::CourseFinished, student.lock()->get_name());
  }
}

std::weak_ptr<Course> Professor::get_current_course() const {
  return _currentCourse;
}

void Professor::on_ring(Event event) {
  if (event == Event::RingBell) {
    std::cout << "Professor: " << get_name() << " heard the bell";
    if (_currentCourse.expired()) {
      std::cout << " but has no course to teach\n";
      return;
    }
    if (!_currentRoom.lock()) {
      std::cout << " and will head to a classroom\n";
      doClass();
    }
    else {
      std::cout << " and will end the class\n";
      check_graduation_requests();
      exit_room();
    }
  }
}
