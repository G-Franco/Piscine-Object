/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 15:45:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include "Student.hpp"

class Course;
class Professor;
class Student;

class Classroom : public Room {
  private:
  	Course* _course;

  public:
  	Classroom();
    Classroom(const Classroom &copy);
    Classroom &operator=(const Classroom &copy);
    bool operator==(const Classroom &other) const;
    ~Classroom();
    bool canEnter(Person*);
  	void assignCourse(Course* p_course);
    Course* getCourse() const;
};
