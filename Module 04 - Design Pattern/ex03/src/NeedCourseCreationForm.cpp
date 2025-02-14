/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:10:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 10:12:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm()
  : Form(FormType::NeedCourseCreation) {}

NeedCourseCreationForm::NeedCourseCreationForm(const NeedCourseCreationForm &copy)
  : Form(copy),
    _course_name(copy._course_name) {}

NeedCourseCreationForm &NeedCourseCreationForm::operator=(const NeedCourseCreationForm &copy) {
  _course_name = copy._course_name;
  return *this;
}

NeedCourseCreationForm::~NeedCourseCreationForm() {}

void NeedCourseCreationForm::set_course_name(std::string course_name) {
  if (course_name.empty()) {
    std::cout << "[SET COURSE NAME] Course name is empty\n";
    return;
  }
  if (check_signed() || check_executed()) {
    std::cout << "[SET COURSE NAME] Form already processed. "
              << "Cannot change course name\n";
    return;
  }
  _course_name = course_name;
}

void NeedCourseCreationForm::sign() {
  if (_course_name.empty()) {
    std::cout << "[SIGN] Course name missing\n";
    return;
  }
  if (check_signed()) {
    std::cout << "[SIGN] Form already signed\n";
    return;
  }
  _signed = true;
  std::cout << "Need course creation form signed for course: "
            << _course_name << "\n";
}

void NeedCourseCreationForm::execute() {
  if (!check_signed()) {
    std::cout << "[EXECUTE] Form not signed\n";
    return;
  }
  if (check_executed()) {
    std::cout << "[EXECUTE] Form already executed\n";
    return;
  }
  _executed = true;
  std::cout << "Need course creation form executed for course: "
            << _course_name << "\n";
}
