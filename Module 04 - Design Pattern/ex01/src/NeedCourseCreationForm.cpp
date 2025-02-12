/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:10:35 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:11:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm()
  : Form(FormType::NeedCourseCreation) {}

NeedCourseCreationForm::NeedCourseCreationForm(const NeedCourseCreationForm &copy)
  : Form(copy) {}

NeedCourseCreationForm &NeedCourseCreationForm::operator=(const NeedCourseCreationForm &copy) {
  (void)copy;
  return *this;
}

NeedCourseCreationForm::~NeedCourseCreationForm() {}

void NeedCourseCreationForm::execute() {
  std::cout << "Need course creation form executed\n";
}
