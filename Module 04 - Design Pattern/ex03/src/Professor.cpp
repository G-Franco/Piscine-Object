/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:33:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:09:02 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Professor.hpp"
#include "../include/Headmaster.hpp"
#include "../include/Course.hpp"

Professor::Professor(std::string p_name)
  : Staff(p_name),
    _currentCourse(nullptr) {}

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
  std::shared_ptr<Person> self = shared_from_this();
  _headmaster->request(self, FormType::NeedCourseCreation, course_name);
}

void Professor::request_graduation(std::shared_ptr<Student> &student) {
  if (!_currentCourse) {
    std::cout << "[REQUEST GRADUATION] Course is null\n";
    return;
  }
  if (!student->is_subscribed(_currentCourse)) {
    std::cout << student->get_name() << " is not subscribed to " << _currentCourse->get_name() << "\n";
    return;
  }
  std::shared_ptr<Person> self = shared_from_this();
  _headmaster->request(self, FormType::CourseFinished, student->get_name());
}

void Professor::assignCourse(std::shared_ptr<Course> &p_course) {
  if (p_course) {
    p_course->assign(nullptr);
  }
  _currentCourse = p_course;
}

void Professor::doClass() {
  if (!_currentCourse) {
    std::cout << "[DO CLASS] Course is null\n";
    return;
  }
  std::shared_ptr<Classroom> classroom = _currentCourse->get_empty_classroom();
  if (!classroom) {
    std::cout << "No classroom available for " << _currentCourse->get_name() << "\n";
    std::shared_ptr<Person> self = shared_from_this();
    _headmaster->request(self, FormType::NeedMoreClassRoom, "");
  }
  classroom = _currentCourse->get_empty_classroom();
  auto self = shared_from_this();
  if (classroom->enter(self)) {
    std::cout << "Professor will hold class: " << _currentCourse->get_name() << "\n";
  }
}

void Professor::closeCourse() {
  if (!_currentCourse) {
    std::cout << "[CLOSE COURSE] Course is null\n";
    return;
  }
  std::cout << "Professor closed course: " << _currentCourse->get_name() << "\n";
  _currentCourse = nullptr;
}

std::shared_ptr<Course> Professor::get_current_course() const {
  return _currentCourse;
}
