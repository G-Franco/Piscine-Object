/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:49:48 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 16:51:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Course.hpp"

Course::Course(std::string p_name)
  : _name(p_name) {}

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

bool Course::operator==(const Course &other) {
  return _name == other._name;
}

Course::~Course() {}

void Course::assign(Professor* p_professor) {
  if (!p_professor) {
    std::cout << "Professor is null" << std::endl;
    return;
  }
  _responsible = p_professor;
}

void Course::subscribe(Student* p_student) {
  if (_students.size() >= (size_t)_maximumNumberOfStudent) {
    std::cout << "Course " + _name + " is full" << std::endl;
    return;
  }
  _students.push_back(p_student);
}

std::string Course::get_name() const {
  return _name;
}


