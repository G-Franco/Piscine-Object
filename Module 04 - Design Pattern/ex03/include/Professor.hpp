/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 15:22:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"
#include "Headmaster.hpp"

class Course;

class Professor : public Staff {
  private:
  	Course* _currentCourse;
    Headmaster &headmaster;

    Professor();
  
  public:
    Professor(std::string p_name, Headmaster &headmaster);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    ~Professor();
  	void assignCourse(Course* p_course);
  	void doClass();
  	void closeCourse();
};
