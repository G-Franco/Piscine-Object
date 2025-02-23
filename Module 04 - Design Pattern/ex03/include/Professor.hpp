/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/22 17:11:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"

class Course;
class Student;

class Professor : public Staff {
  private:
    std::shared_ptr<Course> _currentCourse;

    Professor();
  
  public:
    Professor(std::string p_name);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    bool operator==(const Professor &other) const;
    bool operator==(const std::string name) const;
    ~Professor();
    void request_course(std::string course_name);
    void request_graduation(std::shared_ptr<Student> &student);
  	void assignCourse(std::shared_ptr<Course> &p_course);
  	void doClass();
  	void closeCourse();
    std::shared_ptr<Course> get_current_course() const;
};
