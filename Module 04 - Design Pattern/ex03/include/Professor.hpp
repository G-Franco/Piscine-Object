/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/25 12:10:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"

class Course;
class Student;

class Professor : public Staff {
  private:
    std::weak_ptr<Professor> _self;
    std::weak_ptr<Course> _currentCourse;

    Professor();
  
  public:
    Professor(std::string name);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    bool operator==(const Professor &other) const;
    bool operator==(const std::string name) const;
    ~Professor();
    void set_self(std::weak_ptr<Professor> self);
    void request_course(std::string course_name);
    void request_graduation(std::weak_ptr<Student> &student);
  	void assignCourse(std::weak_ptr<Course> &course);
  	void doClass();
  	void closeCourse();
    std::weak_ptr<Course> get_current_course() const;
};
