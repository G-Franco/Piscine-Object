/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 17:22:26 by gacorrei         ###   ########.fr       */
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
    std::shared_ptr<Course> _currentCourse;
    Headmaster &_headmaster;

    Professor();
  
  public:
    Professor(std::string p_name, Headmaster &headmaster);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    ~Professor();
    void request_course(std::string course_name);
    void request_graduation(Student &student);
  	void assignCourse(std::shared_ptr<Course> p_course);
  	void doClass();
  	void closeCourse();
    std::shared_ptr<Course> get_current_course() const;
};
