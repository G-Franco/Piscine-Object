/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 17:59:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Secretary.hpp"
#include "Bell.hpp"

class Form;
class Professor;
class Student;
class Classroom;
class Course;

class Headmaster : public Staff {
  private:
  	std::vector<std::shared_ptr<Form> > _formToValidate;
  	std::vector<std::shared_ptr<Professor> > _professors;
    std::vector<std::shared_ptr<Student> > _students;
    std::vector<std::shared_ptr<Course> > _courses;
    std::vector<std::shared_ptr<Classroom> > _classrooms;
    Secretary _secretary;
    Bell _bell;

    Headmaster();

  public:
    Headmaster(std::string p_name);
    Headmaster(const Headmaster &copy);
    Headmaster &operator=(const Headmaster &copy);
    ~Headmaster();

    std::weak_ptr<Professor> add_professor(std::string name);
    std::weak_ptr<Student> add_student(std::string name);
    std::weak_ptr<Course> add_course(std::string name);
    std::weak_ptr<Classroom> add_classroom();
    void remove_professor(std::weak_ptr<Professor> &professor);
    void remove_student(std::weak_ptr<Student> &student);
    void remove_course(std::weak_ptr<Course> &course);
    void remove_classroom(std::weak_ptr<Classroom> &classroom);

    std::weak_ptr<Professor> check_professor(std::weak_ptr<Person> &person);
    std::weak_ptr<Student> check_student(std::weak_ptr<Person> &person);
    bool request(std::weak_ptr<Person> &person, FormType form_type, std::string info);
    bool request_course_creation(std::weak_ptr<Professor> &professor, std::string info);
    bool request_course_finished(std::weak_ptr<Professor> &professor, std::string info);
    bool request_classroom_creation(std::weak_ptr<Professor> &professor);
    bool request_course_subscription(std::weak_ptr<Student> &student, std::string info);

  	void receiveForm(std::shared_ptr<Form> &p_form);
    void sign_form(std::shared_ptr<Form> &form);
    void execute_form(std::shared_ptr<Form> &form);
    void sign_all_forms();
    void execute_all_forms();
    void clean_forms(Secretary &secretary);

    void start_class();
    void start_class(std::weak_ptr<Professor> &professor);
    void attend_class();
    void attend_class(std::weak_ptr<Student> &student, std::weak_ptr<Course> &course);

    void add_observer(std::weak_ptr<IObserver> &observer);
    void remove_observer(std::weak_ptr<IObserver> &observer);
    void ring_bell();

    std::weak_ptr<Course> get_course(std::string name);
    std::vector<std::weak_ptr<Student> > get_students();
    std::vector<std::weak_ptr<Professor> > get_professors();
    Secretary get_secretary();
};
