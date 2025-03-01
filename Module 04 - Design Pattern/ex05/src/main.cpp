/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 15:37:39 by gacorrei         ###   ########.fr       */
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
  std::weak_ptr<IObserver> prof_obs = professor_ptr;
  std::weak_ptr<IObserver> stud_obs = student_ptr;
  headmaster.add_observer(stud_obs);
  headmaster.add_observer(prof_obs);
  auto professor = professor_ptr.lock();
  auto student = student_ptr.lock();


  std::cout << "Testing ring bell with no possible classes\n";
  headmaster.ring_bell();
  
  std::cout << "\nTesting ring bell\n";
  professor->request_course("Chemistry");
  std::weak_ptr<Course> course_ptr = professor->get_current_course();
  auto course = course_ptr.lock();
  course->set_number_of_classes_to_graduate(4);
  course->set_maximum_number_of_students(15);
  student->choose_class("Chemistry");
  for (int i = 0; i < 9; i++) {
    std::cout << "\n";
    headmaster.ring_bell();
  }
  return 0;
}
