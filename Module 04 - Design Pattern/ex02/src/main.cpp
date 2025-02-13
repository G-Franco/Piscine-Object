/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 17:25:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Headmaster.hpp"
#include "../include/Professor.hpp"
#include "../include/Staff.hpp"
#include "../include/Student.hpp"
#include "../include/Classroom.hpp"
#include "../include/Courtyard.hpp"
#include "../include/HeadmasterOffice.hpp"
#include "../include/SecretarialOffice.hpp"
#include "../include/StaffRestRoom.hpp"
#include "../include/CourseFinishedForm.hpp"
#include "../include/NeedMoreClassRoomForm.hpp"
#include "../include/NeedCourseCreationForm.hpp"
#include "../include/SubscriptionToCourseForm.hpp"
#include "../include/singetons.hpp"

int main() {
  Headmaster headmaster("John");
  Secretary secretary("Jane");
  Course course("C++");

  std::cout << "Test form creation (Factory pattern)\n";
  auto form1 = secretary.createForm(FormType::CourseFinished);
  auto form2 = secretary.createForm(FormType::NeedMoreClassRoom);
  auto form3 = secretary.createForm(FormType::NeedCourseCreation);
  auto form4 = secretary.createForm(FormType::SubscriptionToCourse);

  std::cout << "\nCheck that all forms are unsigned and not executed\n";
  std::cout << "Form 1: signed: " << form1->check_signed() 
            << " executed: " << form1->check_executed() << "\n";
  std::cout << "Form 2: signed: " << form2->check_signed() 
            << " executed: " << form2->check_executed() << "\n";
  std::cout << "Form 3: signed: " << form3->check_signed() 
            << " executed: " << form3->check_executed() << "\n";
  std::cout << "Form 4: signed: " << form4->check_signed()
            << " executed: " << form4->check_executed() << "\n";

  std::cout << "\nTest form signing and execution before being accepted\n";
  headmaster.sign_form(form1);
  headmaster.execute_form(form2);

  std::cout << "\nFill out some forms\n";
  // Need to downcast to the correct form type to access non virtual functions
  auto courseFinishedForm = std::dynamic_pointer_cast<CourseFinishedForm>(form1);
  courseFinishedForm->set_course(&course);
  auto needMoreClassRoomForm = std::dynamic_pointer_cast<NeedMoreClassRoomForm>(form2);
  std::cout << "Testing invalid number of classrooms\n";
  needMoreClassRoomForm->set_classrooms_needed(10);
  needMoreClassRoomForm->set_classrooms_needed(-1);
  needMoreClassRoomForm->set_classrooms_needed(3);

  std::cout << "\nTest form reception\n";
  headmaster.receiveForm(form1);
  headmaster.receiveForm(form2);
  headmaster.receiveForm(form3);
  headmaster.receiveForm(form4);
  
  std::cout << "\nTest form signing when form has not been filled\n";
  headmaster.sign_form(form3);
  headmaster.sign_form(form4);
  
  std::cout << "\nFill out remaining forms\n";
  auto needCourseCreationForm = std::dynamic_pointer_cast<NeedCourseCreationForm>(form3);
  needCourseCreationForm->set_course_name("Python");
  auto subscriptionToCourseForm = std::dynamic_pointer_cast<SubscriptionToCourseForm>(form4);
  subscriptionToCourseForm->set_course(&course);

  std::cout << "\nTest form execution without signing\n";
  headmaster.execute_form(form1);

  std::cout << "\nTest form signing and execution\n";
  headmaster.sign_form(form1);
  headmaster.sign_form(form2);
  headmaster.sign_form(form3);
  headmaster.sign_form(form4);

  std::cout << "\nTest form signing and execution after being signed\n";
  headmaster.sign_form(form3);
  headmaster.execute_form(form4);

  std::cout << "\nTest cleaning forms\n";
  headmaster.clean_forms(secretary);

  std::cout << "\nTest final archive size\n";
  std::cout << "Archive size: " << secretary.get_archive_size() << "\n";

  std::cout << "\nTest form cleaning when not all forms are executed\n";
  auto form5 = secretary.createForm(FormType::CourseFinished);
  auto form6 = secretary.createForm(FormType::NeedMoreClassRoom);
  auto test1 = std::dynamic_pointer_cast<CourseFinishedForm>(form5);
  test1->set_course(&course);
  auto test2 = std::dynamic_pointer_cast<NeedMoreClassRoomForm>(form6);
  test2->set_classrooms_needed(2);
  headmaster.receiveForm(form5);
  headmaster.receiveForm(form6);
  headmaster.sign_form(form5);
  headmaster.sign_form(form6);
  headmaster.execute_form(form5);
  headmaster.clean_forms(secretary);
  std::cout << "Archive size: " << secretary.get_archive_size() << "\n";
  headmaster.execute_form(form6);
  headmaster.clean_forms(secretary);
  std::cout << "Archive size: " << secretary.get_archive_size() << "\n";
  
  std::cout << "\nTest nullptr cases\n";
  headmaster.receiveForm(nullptr);
  headmaster.sign_form(nullptr);
  headmaster.execute_form(nullptr);
  secretary.archiveForm(nullptr);
  return 0;
}
