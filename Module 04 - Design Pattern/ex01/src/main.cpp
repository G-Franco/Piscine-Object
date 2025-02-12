/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 11:35:53 by gacorrei         ###   ########.fr       */
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
  Singleton<Student> &StudentList = Singleton<Student>::get_instance();
  Singleton<Staff> &StaffList = Singleton<Staff>::get_instance();
  Singleton<Course> &CourseList = Singleton<Course>::get_instance();
  Singleton<Room> &RoomList = Singleton<Room>::get_instance();
}
