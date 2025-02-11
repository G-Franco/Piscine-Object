/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:11:16 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:11:34 by gacorrei         ###   ########.fr       */
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

void SubscriptionToCourseForm::execute() {
  std::cout << "Subscription to course form executed\n";
}
