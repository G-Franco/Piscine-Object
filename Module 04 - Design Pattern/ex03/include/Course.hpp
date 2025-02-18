/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/18 15:49:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "Student.hpp"
#include "Professor.hpp"

// TODO: DON'T FORGET TO CHECK WHERE RINGBELL GOES
class Student;
class Professor;

class Course {
  private:
  	std::string _name;
  	Professor* _responsible;
    std::vector<Classroom *> _classrooms;
  	std::map<Student *, int> _students;
  	int _numberOfClassToGraduate;
  	int _maximumNumberOfStudent;

    Course();

    public:
  	Course(std::string p_name);
    Course(const Course &copy);
    Course &operator=(const Course &copy);
    bool operator==(const Course &other);
    bool operator==(const std::string name) const;
    ~Course();
    void set_number_of_classes_to_graduate(int number);
    void set_maximum_number_of_students(int number);
  	void assign(Professor* p_professor);
    bool course_checks();
  	bool subscribe(Student *p_student);
    void remove_student(Student *p_student);
    void class_attendance(Student* student);
    std::string get_name() const;
    bool check_student(Student* student);
    void add_classroom(Classroom *classroom);
    void remove_classroom(Classroom *classroom);
};
