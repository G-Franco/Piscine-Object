/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:19 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/18 15:19:15 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

class Course;
class Classroom;

class Student : public Person {
  private:
  	std::vector<Course*> _subscribedCourses;
    Headmaster &_headmaster;

    Student();

  public:
    Student(std::string name, Headmaster &headmaster);
    Student(const Student &copy);
    Student &operator=(const Student &copy);
    bool operator==(const Student &other) const;
    bool operator==(const std::string name) const;
    ~Student();
    void choose_class(std::string course_name);
    bool subscribe(Course* p_course);
  	void attendClass(Classroom* p_classroom);
  	void exitClass();
  	void graduate(Course* course);
};
