/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:33:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 15:22:39 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Professor.hpp"

Professor::Professor(std::string p_name, Headmaster &headmaster)
  : Staff(p_name),
    _currentCourse(nullptr),
    headmaster(headmaster) {}

Professor::Professor(const Professor &copy)
  : Staff(copy),
    _currentCourse(copy._currentCourse),
    headmaster(copy.headmaster) {}

Professor &Professor::operator=(const Professor &copy) {
  _currentCourse = copy._currentCourse;
  headmaster = copy.headmaster;
  return *this;
}

Professor::~Professor() {}

void Professor::assignCourse(Course* p_course) {
  if (!p_course) {
    std::cout << "[ASSIGN COURSE] Course is null\n";
    return;
  }
  _currentCourse = p_course;
}

void Professor::doClass() {
  if (!_currentCourse) {
    std::cout << "[DO CLASS] Course is null\n";
    return;
  }
  std::cout << "Professor will teach " << _currentCourse->get_name() << "\n";
}

void Professor::closeCourse() {
  if (!_currentCourse) {
    std::cout << "[CLOSE COURSE] Course is null\n";
    return;
  }
  std::cout << "Professor closed course: " << _currentCourse->get_name() << "\n";
}
