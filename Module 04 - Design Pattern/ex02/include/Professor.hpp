/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 14:32:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"

class Course;

class Professor : public Staff {
  private:
  	Course* _currentCourse;

    Professor();
  
  public:
    Professor(std::string p_name);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    ~Professor();
  	void assignCourse(Course* p_course);
  	void doClass();
  	void closeCourse();
};
