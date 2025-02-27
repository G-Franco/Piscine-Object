/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 10:47:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Headmaster.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"
#include "../include/Course.hpp"

int main() {
  Headmaster headmaster("Gus");
  std::weak_ptr<Professor> professor_ptr = headmaster.add_professor("Walter");
  std::weak_ptr<Student> student_ptr = headmaster.add_student("Jesse");
  auto professor = professor_ptr.lock();
  auto student = student_ptr.lock();

  std::cout << "Testing course creation request\n";
  std::cout << "Professor has no course assigned: \n";
  professor->doClass();
  professor->request_course("Chemistry");
  std::weak_ptr<Course> course_ptr = professor->get_current_course();
  auto course = course_ptr.lock();
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
  headmaster.start_class(professor_ptr);
  headmaster.attend_class(course_ptr);
  return 0;
}
