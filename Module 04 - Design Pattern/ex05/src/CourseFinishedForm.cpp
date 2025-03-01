/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 14:30:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CourseFinishedForm.hpp"
#include "../include/Course.hpp"

CourseFinishedForm::CourseFinishedForm()
  : Form(FormType::CourseFinished),
    _course(std::weak_ptr<Course>()) {}

CourseFinishedForm::CourseFinishedForm(const CourseFinishedForm &copy)
  : Form(copy) {}
  
CourseFinishedForm &CourseFinishedForm::operator=(const CourseFinishedForm &copy) {
  _course = copy._course;
  return *this;
}

CourseFinishedForm::~CourseFinishedForm() {}

void CourseFinishedForm::set_course(std::weak_ptr<Course> course) {
  if (course.expired()) {
    std::cout << "[SET COURSE] Course is null\n";
    return;
  }
  if (check_signed() || check_executed()) {
    std::cout << "[SET COURSE] Form already processed. Cannot change course\n";
    return;
  }
  _course = course;
}

void CourseFinishedForm::sign() {
  if (_course.expired()) {
    std::cout << "[SIGN] Course information missing\n";
    return;
  }
  auto crs = _course.lock();
  if (check_signed()) {
    std::cout << "[SIGN] Form already signed\n";
    return;
  }
  _signed = true;
  std::cout << "Course finished form for: " << crs->get_name() << " signed\n";
}

void CourseFinishedForm::execute() {
  if (_course.expired()) {
    std::cout << "[EXECUTE] Course information missing\n";
    return;
  }
  if (!check_signed()) {
    std::cout << "[EXECUTE] Form not signed\n";
    return;
  }
  if (check_executed()) {
    std::cout << "[EXECUTE] Form already executed\n";
    return;
  }
  _executed = true;
  std::cout << "Course finished form for: " << _course.lock()->get_name() << " executed\n";
}
