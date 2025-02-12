/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:19 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:13:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

class Student : public Person {
  private:
  	std::vector<Course*> _subscribedCourse;

    Student();

  public:
    Student(std::string name);
    Student(const Student &copy);
    Student &operator=(const Student &copy);
    ~Student();
  	void attendClass(Classroom* p_classroom);
  	void exitClass();
  	void graduate(Course* p_course);
};
