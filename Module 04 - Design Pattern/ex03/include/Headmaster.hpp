/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 18:20:56 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "singetons.hpp"

class Professor;
class Student;
class Secretary;
class Classroom;
class Course;

class Headmaster : public Staff {
  private:
  	std::vector<std::shared_ptr<Form> > _formToValidate;
  	Singleton<Professor> &_professors;
    Singleton<Student> &_students;
    Singleton<Course> &_courses;
    Singleton<Classroom> &_classrooms;
    Secretary _secretary;

    Headmaster();

  public:
    Headmaster(std::string p_name);
    Headmaster(const Headmaster &copy);
    Headmaster &operator=(const Headmaster &copy);
    ~Headmaster();

    void add_professor(Professor &professor);
    void add_student(Student &student);
    void add_course(Course &course);
    void add_classroom(Classroom &classroom);

    Professor *check_professor(Person &person);
    Student *check_student(Person &person);
    void request(Person &person, FormType form_type, std::string info);
    void request_course_creation(Professor *professor, std::string info);
    void request_course_finished(Professor *professor, std::string info);
    void request_course_subscription(Student *student, std::string info);
    void request_classroom_creation(Professor *professor);

  	void receiveForm(std::shared_ptr<Form> p_form);
    void sign_form(std::shared_ptr<Form> form);
    void execute_form(std::shared_ptr<Form> form);
    void sign_all_forms();
    void execute_all_forms();
    void clean_forms(Secretary &secretary);

    void start_class();
    void start_class(Professor &professor);
    void attend_class(Course &course);
    void attend_class(Student &student, Course &course);
};
