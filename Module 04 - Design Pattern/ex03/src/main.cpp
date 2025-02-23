/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:14:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Headmaster.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"
#include "../include/Course.hpp"

int main() {
  std::shared_ptr<Headmaster> headmaster = std::make_shared<Headmaster>("Gus");
  std::shared_ptr<Professor> professor = std::make_shared<Professor>("Walter");
  std::shared_ptr<Student> student = std::make_shared<Student>("Jesse");
  headmaster->add_professor(professor);
  headmaster->add_student(student);

  std::cout << "Testing course creation request\n";
  std::cout << "Professor has no course assigned: \n"
            << professor->get_current_course() << "\n";
  professor->doClass();
  professor->request_course("Chemistry");
  std::shared_ptr<Course> course = professor->get_current_course(); 
  std::cout << "After the request, professor has a course assigned: \n"
            << course->get_name() << "\n";
  // Only 1 class to graduate doesn't make sense but it's just for testing
  course->set_number_of_classes_to_graduate(1);
  course->set_maximum_number_of_students(10);

  std::cout << "\nTesting course enrollment request\n";
  std::cout << "Student is not subscribed to any course: \n"
            << "Number of courses: " 
            << student->get_subscribed_courses().size() << "\n";
  std::cout << "\nChoosing non-existing course: \n";
  student->choose_class("Economics");
  std::cout << "Choosing existing course: \n";
  student->choose_class("Chemistry");
  std::cout << "Student is now subscribed to course: \n"
            << "Number of courses: " 
            << student->get_subscribed_courses().size() << "\n";
  
  std::cout << "\nTesting room creation request\n";
  std::cout << "Graduation request is triggered automatically for this test case\n";
  std::cout << "When professor tries to start class without classroom: \n";
  headmaster->start_class(professor);
  headmaster->attend_class(course);
  
  return 0;
}
