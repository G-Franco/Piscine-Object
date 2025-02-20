/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:33:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 18:22:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Professor.hpp"
#include "../include/Headmaster.hpp"
#include "../include/Course.hpp"

Professor::Professor(std::string p_name, Headmaster &headmaster)
  : Staff(p_name),
    _currentCourse(nullptr),
    _headmaster(headmaster) {}

Professor::Professor(const Professor &copy)
  : Staff(copy),
    _currentCourse(copy._currentCourse),
    _headmaster(copy._headmaster) {}

Professor &Professor::operator=(const Professor &copy) {
  _currentCourse = copy._currentCourse;
  _headmaster = copy._headmaster;
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
  _headmaster.request(*this, FormType::NeedCourseCreation, course_name);
}

void Professor::request_graduation(Student &student) {
  _headmaster.request(*this, FormType::CourseFinished, student.get_name());
  _currentCourse->remove_student(&student);
  student.graduate(_currentCourse);
}

void Professor::assignCourse(Course *p_course) {
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
  Classroom *classroom = _currentCourse->get_empty_classroom();
  if (!classroom) {
    std::cout << "No classroom available for " << _currentCourse->get_name() << "\n";
    _headmaster.request(*this, FormType::NeedMoreClassRoom, "");
  }
  classroom = _currentCourse->get_empty_classroom();
  if (classroom->enter(this)) {
    std::cout << "Professor will hold class: " << _currentCourse->get_name() << "\n";
  }
}

void Professor::closeCourse() {
  if (!_currentCourse) {
    std::cout << "[CLOSE COURSE] Course is null\n";
    return;
  }
  std::cout << "Professor closed course: " << _currentCourse->get_name() << "\n";
}

Course *Professor::get_current_course() const {
  return _currentCourse;
}
