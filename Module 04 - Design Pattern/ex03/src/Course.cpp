/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:49:48 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:52:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Course.hpp"

Course::Course(std::string p_name)
  : _name(p_name),
    _responsible(nullptr),
    _numberOfClassToGraduate(0),
    _maximumNumberOfStudent(0) {}

Course::Course(const Course &copy) 
  : std::enable_shared_from_this<Course>(),
    _name(copy._name),
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

Course::~Course() {}

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
void Course::assign(std::shared_ptr<Professor> p_professor) {
  _responsible = p_professor;
}

bool Course::course_checks() {
  if (!_responsible) {
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

bool Course::subscribe(std::shared_ptr<Student> &p_student) {
  if (!course_checks()) {
    return false;
  }
  if (!p_student) {
    std::cout << "Student is null\n";
    return false;
  }
  if (_students.size() >= (size_t)_maximumNumberOfStudent) {
    std::cout << "Course: " + _name + " is full\n";
    return false;
  }
  _students.emplace(p_student, 0);
  return true;
}

void Course::remove_student(std::shared_ptr<Student> &p_student) {
  if (!course_checks()) {
    return;
  }
  if (!p_student) {
    std::cout << "Student is null\n";
    return;
  }
  if (_students.find(p_student) == _students.end()) {
    std::cout << "Student is not subscribed to course: " + _name + "\n";
    return;
  }
  _students.erase(p_student);
}

std::string Course::get_name() const {
  return _name;
}

void Course::class_attendance(std::shared_ptr<Student> &student) {
  if (!course_checks()) {
    return;
  }
  if (!student) {
    std::cout << "Student is null\n";
    return;
  }
  if (_students.find(student) == _students.end()) {
    std::cout << "Student is not subscribed to course: " + _name + "\n";
    return;
  }
  if (++_students[student] == _numberOfClassToGraduate) {
    _responsible->request_graduation(student);
  }
}

bool Course::check_student(std::shared_ptr<Student> &student) {
  if (!student) {
    std::cout << "Student is null\n";
    return false;
  }
  if (_students.find(student) == _students.end()) {
    std::cout << "Student is not subscribed to course: " + _name + "\n";
    return false;
  }
  return true;
}

void Course::add_classroom(std::shared_ptr<Classroom> &classroom) {
  if (!classroom) {
    std::cout << "Classroom is null\n";
    return;
  }
  if (classroom->getCourse()) {
    std::cout << "Classroom already has a course\n";
    return;
  }
  if (std::find(_classrooms.begin(), _classrooms.end(), classroom) != _classrooms.end()) {
    std::cout << "Classroom already assigned\n";
    return;
  }
  _classrooms.push_back(classroom);
  auto self = shared_from_this();
  classroom->assignCourse(self);
}

void Course::remove_classroom(std::shared_ptr<Classroom> &classroom) {
  if (!classroom) {
    std::cout << "Classroom is null\n";
    return;
  }
  auto it = std::find(_classrooms.begin(), _classrooms.end(), classroom);
  if (it == _classrooms.end()) {
    std::cout << "Classroom is not assigned\n";
    return;
  }
  (*it)->assignCourse(nullptr);
  _classrooms.erase(it);
}

std::vector<std::shared_ptr<Classroom> > Course::get_classrooms() const {
  return _classrooms;
}

std::shared_ptr<Classroom> Course::get_empty_classroom() {
  for (auto &classroom : _classrooms) {
    if (classroom->is_empty()) {
      return classroom;
    }
  }
  return nullptr;
}
