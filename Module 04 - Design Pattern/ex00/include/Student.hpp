/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:19 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:38:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

class Student : public Person {
  private:
  	std::vector<Course*> _subscribedCourse;
  
  public:
  	void attendClass(Classroom* p_classroom);
  	void exitClass();
  	void graduate(Course* p_course);
};
