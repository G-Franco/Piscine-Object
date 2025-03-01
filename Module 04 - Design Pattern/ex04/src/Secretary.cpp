/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:30:49 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/28 12:53:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Secretary.hpp"
#include "../include/CourseFinishedForm.hpp"
#include "../include/NeedMoreClassRoomForm.hpp"
#include "../include/NeedCourseCreationForm.hpp"
#include "../include/SubscriptionToCourseForm.hpp"

Secretary::Secretary(std::string p_name)
  : Staff(p_name) {}

Secretary::Secretary(const Secretary &copy)
  : Staff(copy) {}

Secretary &Secretary::operator=(const Secretary &copy) {
  (void)copy;
  return *this;
}

Secretary::~Secretary() {
  _form_archive.clear();
}

std::shared_ptr<Form> Secretary::createForm(FormType p_formType) {
  switch (p_formType) {
    case FormType::CourseFinished:
      return std::make_shared<CourseFinishedForm>();
    case FormType::NeedMoreClassRoom:
      return std::make_shared<NeedMoreClassRoomForm>();
    case FormType::NeedCourseCreation:
      return std::make_shared<NeedCourseCreationForm>();
    case FormType::SubscriptionToCourse:
      return std::make_shared<SubscriptionToCourseForm>();
    default:
      return nullptr;
  }
}

void Secretary::archiveForm(std::shared_ptr<Form> p_form) {
  if (!p_form) {
    std::cout << "[ARCHIVE FORM] Form is null\n";
    return;
  }
  _form_archive.push_back(p_form);  
}

int Secretary::get_archive_size() const {
  return _form_archive.size();
}
