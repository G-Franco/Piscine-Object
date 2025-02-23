/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:52:17 by gacorrei         ###   ########.fr       */
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

class Course : public std::enable_shared_from_this<Course> {
  private:
  	std::string _name;
  	std::shared_ptr<Professor> _responsible;
    std::vector<std::shared_ptr<Classroom> > _classrooms;
  	std::map<std::shared_ptr<Student>, int> _students;
  	int _numberOfClassToGraduate;
  	int _maximumNumberOfStudent;

    Course();

    public:
  	Course(std::string p_name);
    Course(const Course &copy);
    Course &operator=(const Course &copy);
    bool operator==(const Course &other) const;
    bool operator==(const std::string name) const;
    ~Course();
    void set_number_of_classes_to_graduate(int number);
    void set_maximum_number_of_students(int number);
  	void assign(std::shared_ptr<Professor> p_professor);
    bool course_checks();
  	bool subscribe(std::shared_ptr<Student> &p_student);
    void remove_student(std::shared_ptr<Student> &p_student);
    void class_attendance(std::shared_ptr<Student> &student);
    std::string get_name() const;
    bool check_student(std::shared_ptr<Student> &student);
    void add_classroom(std::shared_ptr<Classroom> &classroom);
    void remove_classroom(std::shared_ptr<Classroom> &classroom);
    std::vector<std::shared_ptr<Classroom> > get_classrooms() const;
    std::shared_ptr<Classroom> get_empty_classroom();
};
