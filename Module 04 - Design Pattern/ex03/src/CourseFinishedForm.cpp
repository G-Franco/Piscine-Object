/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 12:11:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CourseFinishedForm.hpp"
#include "../include/Course.hpp"

CourseFinishedForm::CourseFinishedForm()
  : Form(FormType::CourseFinished),
    course(nullptr) {}

CourseFinishedForm::CourseFinishedForm(const CourseFinishedForm &copy)
  : Form(copy) {}
  
CourseFinishedForm &CourseFinishedForm::operator=(const CourseFinishedForm &copy) {
  course = copy.course;
  return *this;
}

CourseFinishedForm::~CourseFinishedForm() {}

void CourseFinishedForm::set_course(std::shared_ptr<Course> p_course) {
  if (!p_course) {
    std::cout << "[SET COURSE] Course is null\n";
    return;
  }
  if (check_signed() || check_executed()) {
    std::cout << "[SET COURSE] Form already processed. Cannot change course\n";
    return;
  }
  course = p_course;
}

void CourseFinishedForm::sign() {
  if (!course) {
    std::cout << "[SIGN] Course information missing\n";
    return;
  }
  if (check_signed()) {
    std::cout << "[SIGN] Form already signed\n";
    return;
  }
  _signed = true;
  std::cout << "Course finished form for: " << course->get_name() << " signed\n";
}

void CourseFinishedForm::execute() {
  if (!check_signed()) {
    std::cout << "[EXECUTE] Form not signed\n";
    return;
  }
  if (check_executed()) {
    std::cout << "[EXECUTE] Form already executed\n";
    return;
  }
  _executed = true;
  std::cout << "Course finished form for: " << course->get_name() << " executed\n";
}
