/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:09:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 12:03:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/NeedMoreClassRoomForm.hpp"
#include "../include/Course.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm()
  : Form(FormType::NeedMoreClassRoom),
    _classrooms_needed(1),
    _course(std::weak_ptr<Course>()) {}

NeedMoreClassRoomForm::NeedMoreClassRoomForm(const NeedMoreClassRoomForm &copy)
  : Form(copy),
    _classrooms_needed(copy._classrooms_needed),
    _course(copy._course) {}

NeedMoreClassRoomForm &NeedMoreClassRoomForm::operator=(const NeedMoreClassRoomForm &copy) {
  _classrooms_needed = copy._classrooms_needed;
  _course = copy._course;
  return *this;
}

NeedMoreClassRoomForm::~NeedMoreClassRoomForm() {}

void NeedMoreClassRoomForm::set_classrooms_needed(int classrooms_needed) {
  if (classrooms_needed < 1 ||
      classrooms_needed > 5) {
    std::cout << "[SET CLASSROOMS NEEDED] Invalid number of classrooms,\n"
              << "Please enter a number between 1 and 5\n";
    return;
  }
  if (check_signed() || check_executed()) {
    std::cout << "[SET CLASSROOMS NEEDED] Form already processed. "
              << "Cannot change number of classrooms\n";
    return;
  }
  _classrooms_needed = classrooms_needed;
}

void NeedMoreClassRoomForm::set_course(std::weak_ptr<Course> &course) {
  if (course.expired()) {
    std::cout << "[SET COURSE] Course is null\n";
    return;
  }
  if (check_signed() || check_executed()) {
    std::cout << "[SET COURSE] Form already processed. "
              << "Cannot change course\n";
    return;
  }
  _course = course;
}

void NeedMoreClassRoomForm::sign() {
  if (check_signed()) {
    std::cout << "[SIGN] Form already signed\n";
    return;
  }
  if (_course.expired()) {
    std::cout << "[SIGN] Course is not set\n";
    return;
  }
  _signed = true;
  std::cout << "Need more classroom form signed for an extra "
            << _classrooms_needed << " classrooms "
            << "for course: " << _course.lock()->get_name() << "\n";
}

void NeedMoreClassRoomForm::execute() {
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
  std::cout << "Need more classroom form executed for an extra "
            << _classrooms_needed << " classrooms\n";
}
