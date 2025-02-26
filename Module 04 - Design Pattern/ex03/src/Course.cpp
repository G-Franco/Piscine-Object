/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:49:48 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 11:51:59 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Course.hpp"

Course::Course(std::string name)
  : _name(name),
    _responsible(std::weak_ptr<Professor>()),
    _numberOfClassToGraduate(0),
    _maximumNumberOfStudent(0) {}

Course::Course(const Course &copy)
  : _name(copy._name),
    _responsible(copy._responsible),
    _students(copy._students),
    _numberOfClassToGraduate(copy._numberOfClassToGraduate),
    _maximumNumberOfStudent(copy._maximumNumberOfStudent) {}

Course &Course::operator=(const Course &copy) {
  _name = copy._name;
  _responsible = copy._responsible;
  _students = copy._students;
  _numberOfClassToGraduate = copy._numberOfClassToGraduate;
  _maximumNumberOfStudent = copy._maximumNumberOfStudent;
  return *this;
}

bool Course::operator==(const Course &other) const {
  return _name == other._name;
}

bool Course::operator==(const std::string name) const {
  return _name == name;
}

Course::~Course() {
  _responsible = std::weak_ptr<Professor>();
  _students.clear();
  _classrooms.clear();
}

void Course::set_self(std::weak_ptr<Course> self) {
  if (self.expired()) {
    std::cout << "Self pointer is empty\n";
    return;
  }
  _self = self;
}

void Course::set_number_of_classes_to_graduate(int number) {
  if (number < 1 || number > 10) {
    std::cout << "Number of classes to graduate must be between 1 and 10\n";
    return;
  }
  _numberOfClassToGraduate = number;
}

void Course::set_maximum_number_of_students(int number) {
  if (number < 10 || number > 20) {
    std::cout << "Maximum number of students must be between 10 and 20\n";
    return;
  }
  _maximumNumberOfStudent = number;
}

// No nullptr check because it can be used to remove the professor
void Course::assign(std::weak_ptr<Professor> professor) {
  _responsible = professor;
}

bool Course::course_checks() {
  if (_responsible.expired()) {
    std::cout << "Course: " + _name + " has no assigned teacher\n";
    return false;
  }
  if (_numberOfClassToGraduate < 1) {
    std::cout << "Course: " + _name + " has no number of classes to graduate\n";
    return false;
  }
  if (_maximumNumberOfStudent < 1) {
    std::cout << "Course: " + _name + " has no maximum number of students\n";
    return false;
  }
  return true;
}

bool Course::subscribe(std::weak_ptr<Student> &student) {
  if (!course_checks()) {
    return false;
  }
  if (student.expired()) {
    std::cout << "Student is null\n";
    return false;
  }
  if (_students.size() >= (size_t)_maximumNumberOfStudent) {
    std::cout << "Course: " + _name + " is full\n";
    return false;
  }
  _students.emplace(student, 0);
  return true;
}

void Course::remove_student(std::weak_ptr<Student> &student) {
  if (!course_checks()) {
    return;
  }
  if (student.expired()) {
    std::cout << "Student is null\n";
    return;
  }
  if (_students.find(student) == _students.end()) {
    std::cout << "Student is not subscribed to course: " + _name + "\n";
    return;
  }
  _students.erase(student);
}

std::string Course::get_name() const {
  return _name;
}

void Course::class_attendance(std::weak_ptr<Student> &student) {
  if (!course_checks()) {
    return;
  }
  if (student.expired()) {
    std::cout << "Student is null\n";
    return;
  }
  if (_students.find(student) == _students.end()) {
    std::cout << "Student is not subscribed to course: " + _name + "\n";
    return;
  }
  if (++_students[student] == _numberOfClassToGraduate) {
    auto responsible = _responsible.lock();
    responsible->request_graduation(student);
  }
}

bool Course::check_student(std::weak_ptr<Student> &student) {
  if (student.expired()) {
    std::cout << "Student is null\n";
    return false;
  }
  if (_students.find(student) == _students.end()) {
    std::cout << "Student is not subscribed to course: " + _name + "\n";
    return false;
  }
  return true;
}

void Course::add_classroom(std::weak_ptr<Classroom> &classroom) {
  if (_self.expired()) {
    std::cout << "Course must have a self pointer\n";
    return;
  }
  if (classroom.expired()) {
    std::cout << "Classroom is null\n";
    return;
  }
  auto room = classroom.lock();
  if (!room->getCourse().expired()) {
    std::cout << "Classroom already has a course\n";
    return;
  }
  if (std::find(_classrooms.begin(), _classrooms.end(), classroom) != _classrooms.end()) {
    std::cout << "Classroom already assigned\n";
    return;
  }
  _classrooms.push_back(classroom);
  room->assignCourse(_self);
}

void Course::remove_classroom(std::weak_ptr<Classroom> &classroom) {
  if (classroom.expired()) {
    std::cout << "Classroom is null\n";
    return;
  }
  auto it = std::find(_classrooms.begin(), _classrooms.end(), classroom);
  if (it == _classrooms.end()) {
    std::cout << "Classroom is not on the list\n";
    return;
  }
  auto room = classroom.lock();
  room->assignCourse(std::weak_ptr<Course>());
  _classrooms.erase(it);
}

std::vector<std::weak_ptr<Classroom> > Course::get_classrooms() const {
  return _classrooms;
}

std::weak_ptr<Classroom> Course::get_empty_classroom() {
  for (auto &classroom : _classrooms) {
    if (classroom.expired()) {
      continue;
    }
    auto room = classroom.lock();
    if (room->is_empty()) {
      return classroom;
    }
  }
  return std::weak_ptr<Classroom>();
}
