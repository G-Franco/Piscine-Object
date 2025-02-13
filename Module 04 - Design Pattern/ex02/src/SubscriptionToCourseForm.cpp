/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:11:16 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 17:22:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm()
  : Form(FormType::SubscriptionToCourse) {}

SubscriptionToCourseForm::SubscriptionToCourseForm(const SubscriptionToCourseForm &copy)
  : Form(copy) {}

SubscriptionToCourseForm &SubscriptionToCourseForm::operator=(const SubscriptionToCourseForm &copy) {
  (void)copy;
  return *this;
}

SubscriptionToCourseForm::~SubscriptionToCourseForm() {}

void SubscriptionToCourseForm::set_course(Course *course) {
  if (!course) {
    std::cout << "[SET COURSE] Course is null\n";
    return;
  }
  if (check_signed() || check_executed()) {
    std::cout << "[SET COURSE] Form already processed. Cannot change course\n";
    return;
  }
  _course = course;
}

void SubscriptionToCourseForm::sign() {
  if (!_course) {
    std::cout << "[SIGN] Course information missing\n";
    return;
  }
  if (check_signed()) {
    std::cout << "[SIGN] Form already signed\n";
    return;
  }
  _signed = true;
  std::cout << "Subscription to course form for: "
            << _course->get_name() << " signed\n";
}

void SubscriptionToCourseForm::execute() {
  if (!check_signed()) {
    std::cout << "[EXECUTE] Form not signed\n";
    return;
  }
  if (check_executed()) {
    std::cout << "[EXECUTE] Form already executed\n";
    return;
  }
  _executed = true;
  std::cout << "Subscription to course form for: "
            << _course->get_name() << " executed\n";
}
