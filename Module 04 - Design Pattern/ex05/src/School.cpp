/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   School.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:25:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/02 11:45:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/School.hpp"

School::School()
  : _headmaster("Dumbledore") {}

School::School(const School &copy)
  : _headmaster(copy._headmaster) {}

School School::operator=(const School &copy) {
  if (this != &copy) {
    _headmaster = copy._headmaster;
  }
  return *this;
}

School::~School() {}

void School::runDayRoutine() {
  std::cout << "\nStart of school day\n";
  launchClasses();
  std:: cout << "\n1st break\n";
  requestRingBell();
  std::cout << "\nBack to classes\n";
  launchClasses();
  std::cout << "\nLunch break\n";
  requestRingBell();
  std::cout << "\nStart of afternoon classes\n";
  launchClasses();
  std::cout << "\n2nd break\n";
  requestRingBell();
  std::cout << "\nBack to classes\n";
  launchClasses();
}

void School::launchClasses() {
  _headmaster.start_class();
  _headmaster.attend_class();
}

void School::requestRingBell() {
  _headmaster.ring_bell();
}

void School::recruteProfessor(std::string name) {
  _headmaster.add_professor(name);
}

void School::recruteStudent(std::string name) {
  _headmaster.add_student(name);
}


std::weak_ptr<Course> School::getCourse(std::string name) {
  return _headmaster.get_course(name);
}

std::vector<std::weak_ptr<Student>> School::getStudents() {
  return _headmaster.get_students();
}

std::vector<std::weak_ptr<Professor>> School::getProfessors() {
  return _headmaster.get_professors();
}

Headmaster School::getHeadmaster() {
  return _headmaster;
}

Secretary School::getSecretary() {
  return _headmaster.get_secretary();
}

void School::graduationCeremony() {
  _headmaster.graduation();
}
