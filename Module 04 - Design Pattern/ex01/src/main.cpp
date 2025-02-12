/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:51:09 by gacorrei         ###   ########.fr       */
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

void print_sizes(Singleton<Student> &StudentList,
                Singleton<Staff> &StaffList,
                Singleton<Course> &CourseList,
                Singleton<Room> &RoomList) {
  std::cout << "StudentList has size: " << StudentList.get_group().size() << "\n"
            << "StaffList has size: " << StaffList.get_group().size() << "\n"
            << "CourseList has size: " << CourseList.get_group().size() << "\n"
            << "RoomList has size: " << RoomList.get_group().size() << "\n";
}

int main() {
  Singleton<Student> &StudentList = Singleton<Student>::get_instance();
  Singleton<Staff> &StaffList = Singleton<Staff>::get_instance();
  Singleton<Course> &CourseList = Singleton<Course>::get_instance();
  Singleton<Room> &RoomList = Singleton<Room>::get_instance();

  std::cout << "Proof that there can only be one\n";
  Singleton<Student> &StudentList2 = Singleton<Student>::get_instance();
  std::cout << "The initial StudentList address is: " << &StudentList << "\n"
            << "The second StudentList address is: " << &StudentList2 << "\n";

  std::cout << "\nAdding entries\n";
  Student Alice("Alice");
  Student Bob("Bob");
  Student Charlie("Charlie");
  StudentList.add(Alice);
  StudentList.add(Bob);
  StudentList.add(Charlie);

  Staff Adam("Adam");
  Staff David("David");
  StaffList.add(Adam);
  StaffList.add(David);

  Course Math("Math");
  Course Physics("Physics");
  Course Chemistry("Chemistry");
  CourseList.add(Math);
  CourseList.add(Physics);
  CourseList.add(Chemistry);

  Classroom Classroom;
  Courtyard Courtyard;
  RoomList.add(Classroom);
  RoomList.add(Courtyard);
  print_sizes(StudentList, StaffList, CourseList, RoomList);
  
  std::cout << "\nRemoving entries\n";
  StudentList.remove(Bob);
  StaffList.remove(David);
  CourseList.remove(Physics);
  RoomList.remove(Courtyard);
  print_sizes(StudentList, StaffList, CourseList, RoomList);

  std::cout << "\nGetting whole vector\n";
  std::vector<Student> students(StudentList.get_group());
  for (auto student : students) {
    std::cout << student.get_name() << "\n";
  }
  
  std::cout << "Test modifying the vector and checking original\n";
  Student Test("Test");
  students.push_back(Test);
  print_sizes(StudentList, StaffList, CourseList, RoomList);
  std::cout << "Retrieved student vector size: " << students.size() << "\n";

  std::cout << "\nGetting elements\n"
            << "First to be added was Alice\n"
            << "First element using get_element is: "
            << StudentList.get_element(0).get_name() << "\n";

  std::cout << "\nTrying to get an element out of bounds\n";
  try {
    StudentList.get_element(3);
  } catch (std::runtime_error &e) {
    std::cout << e.what() << "\n";
  }

  std::cout << "\nTrying to remove an element that doesn't exist\n";
  try {
    Student Mark("Mark");
    StudentList.remove(Mark);
  } catch (std::runtime_error &e) {
    std::cout << e.what() << "\n";
  }

  std::cout << "\nValidate room case, since Room is an base class\n";
  std::cout << "Classroom has id: " << RoomList.get_element(0).get_id() << "\n";

  return 0;
}
