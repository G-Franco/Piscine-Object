/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 15:42:42 by gacorrei         ###   ########.fr       */
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

    void add_professor(std::shared_ptr<Professor> &professor);
    void add_student(std::shared_ptr<Student> &student);
    void add_course(std::shared_ptr<Course> &course);
    void add_classroom(std::shared_ptr<Classroom> &classroom);
    void remove_professor(std::shared_ptr<Professor> &professor);
    void remove_student(std::shared_ptr<Student> &student);
    void remove_course(std::shared_ptr<Course> &course);
    void remove_classroom(std::shared_ptr<Classroom> &classroom);

    std::shared_ptr<Professor> check_professor(std::shared_ptr<Person> &person);
    std::shared_ptr<Student> check_student(std::shared_ptr<Person> &person);
    void request(std::shared_ptr<Person> &person, FormType form_type, std::string info);
    void request_course_creation(std::shared_ptr<Professor> &professor, std::string info);
    void request_course_finished(std::shared_ptr<Professor> &professor, std::string info);
    void request_classroom_creation(std::shared_ptr<Professor> &professor);
    void request_course_subscription(std::shared_ptr<Student> &student, std::string info);

  	void receiveForm(std::shared_ptr<Form> &p_form);
    void sign_form(std::shared_ptr<Form> &form);
    void execute_form(std::shared_ptr<Form> &form);
    void sign_all_forms();
    void execute_all_forms();
    void clean_forms(Secretary &secretary);

    void start_class();
    void start_class(std::shared_ptr<Professor> &professor);
    void attend_class(std::shared_ptr<Course> &course);
    void attend_class(std::shared_ptr<Student> &student, std::shared_ptr<Course> &course);
};
