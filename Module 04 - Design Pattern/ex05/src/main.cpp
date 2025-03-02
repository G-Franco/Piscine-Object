/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/02 17:35:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Headmaster.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"
#include "../include/Course.hpp"
#include "../include/School.hpp"

void prep(School &school) {
  std::cout << "-----------------------------------\n";
  std::cout << "-----------------------------------\n";

  auto prof1 = school.recruteProfessor("Snape");
  auto prof2 = school.recruteProfessor("McGonagall");
  auto prof3 = school.recruteProfessor("Flitwick");
  auto prof4 = school.recruteProfessor("Sprout");
  auto prof5 = school.recruteProfessor("Trelawney");

  auto stud1 = school.recruteStudent("Harry");
  auto stud2 = school.recruteStudent("Ron");
  auto stud3 = school.recruteStudent("Hermione");
  auto stud4 = school.recruteStudent("Neville");
  auto stud5 = school.recruteStudent("Draco");
  auto stud6 = school.recruteStudent("Luna");
  auto stud7 = school.recruteStudent("Ginny");
  auto stud8 = school.recruteStudent("Fred");
  auto stud9 = school.recruteStudent("George");
  auto stud10 = school.recruteStudent("Percy");

  prof1.lock()->request_course("Potions");
  prof2.lock()->request_course("Transfiguration");
  prof3.lock()->request_course("Charms");
  prof4.lock()->request_course("Herbology");
  prof5.lock()->request_course("Divination");

  std::vector<std::weak_ptr<Course>> courses;
  courses.push_back(prof1.lock()->get_current_course());
  courses.push_back(prof2.lock()->get_current_course());
  courses.push_back(prof3.lock()->get_current_course());
  courses.push_back(prof4.lock()->get_current_course());
  courses.push_back(prof5.lock()->get_current_course());

  for (const auto &course : courses) {
    course.lock()->set_maximum_number_of_students(10);
    course.lock()->set_number_of_classes_to_graduate(2);
  }

  stud1.lock()->choose_class("Potions");
  stud2.lock()->choose_class("Potions");
  stud3.lock()->choose_class("Potions");
  stud4.lock()->choose_class("Transfiguration");
  stud5.lock()->choose_class("Transfiguration");
  stud6.lock()->choose_class("Transfiguration");
  stud7.lock()->choose_class("Charms");
  stud8.lock()->choose_class("Charms");
  stud9.lock()->choose_class("Charms");
  stud10.lock()->choose_class("Herbology");
  stud1.lock()->choose_class("Herbology");
  stud2.lock()->choose_class("Herbology");
  stud3.lock()->choose_class("Divination");
  stud4.lock()->choose_class("Divination");
  stud5.lock()->choose_class("Divination");

  std::cout << "-----------------------------------\n";
  std::cout << "-----------------------------------\n";
}

int main() {
  School hogwarts;
  prep(hogwarts);
  hogwarts.runDayRoutine();
  hogwarts.requestRingBell();
  hogwarts.runDayRoutine();
  hogwarts.requestRingBell();
  hogwarts.graduationCeremony();
  return 0;
}
