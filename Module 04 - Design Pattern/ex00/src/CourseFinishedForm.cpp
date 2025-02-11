/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:04:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CourseFinishedForm.hpp"

CourseFinishedForm::CourseFinishedForm()
  : Form(FormType::CourseFinished) {}

CourseFinishedForm::CourseFinishedForm(const CourseFinishedForm &copy)
  : Form(copy) {}
  
CourseFinishedForm &CourseFinishedForm::operator=(const CourseFinishedForm &copy) {
  (void)copy;
  return *this;
}

CourseFinishedForm::~CourseFinishedForm() {}

void CourseFinishedForm::execute() {
  std::cout << "Course finished form executed\n";
}
