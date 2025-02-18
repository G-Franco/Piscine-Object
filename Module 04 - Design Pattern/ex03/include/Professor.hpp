/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/18 15:09:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"
#include "Headmaster.hpp"

class Course;
class Headmaster;

class Professor : public Staff {
  private:
    Course *_currentCourse;
    Headmaster &_headmaster;

    Professor();
  
  public:
    Professor(std::string p_name, Headmaster &headmaster);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    bool operator==(const Professor &other) const;
    bool operator==(const std::string name) const;
    ~Professor();
    void request_course(std::string course_name);
    void request_graduation(Student &student);
  	void assignCourse(Course *p_course);
  	void doClass();
  	void closeCourse();
    Course *get_current_course() const;
};
