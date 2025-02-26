/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 10:51:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "Student.hpp"
#include "Professor.hpp"
#include "Classroom.hpp"

class Student;
class Professor;
class Classroom;

class Course {
  private:
  	std::string _name;
  	std::weak_ptr<Course> _self;
  	std::weak_ptr<Professor> _responsible;
    std::vector<std::weak_ptr<Classroom>> _classrooms;
  	std::map<std::weak_ptr<Student>, int> _students;
  	int _numberOfClassToGraduate;
  	int _maximumNumberOfStudent;

    Course();

    public:
  	Course(std::string name);
    Course(const Course &copy);
    Course &operator=(const Course &copy);
    bool operator==(const Course &other) const;
    bool operator==(const std::string name) const;
    ~Course();
    void set_self(std::weak_ptr<Course> self);
    void set_number_of_classes_to_graduate(int number);
    void set_maximum_number_of_students(int number);
  	void assign(std::weak_ptr<Professor> professor);
    bool course_checks();
  	bool subscribe(std::weak_ptr<Student> &student);
    void remove_student(std::weak_ptr<Student> &student);
    void class_attendance(std::weak_ptr<Student> &student);
    std::string get_name() const;
    bool check_student(std::weak_ptr<Student> &student);
    void add_classroom(std::weak_ptr<Classroom> &classroom);
    void remove_classroom(std::weak_ptr<Classroom> &classroom);
    std::vector<std::weak_ptr<Classroom>> get_classrooms() const;
    std::weak_ptr<Classroom> get_empty_classroom();
};
