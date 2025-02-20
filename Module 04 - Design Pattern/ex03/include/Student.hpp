/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:19 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 18:16:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "Person.hpp"

class Course;
class Headmaster;

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
    void unsubscribe(Course* p_course);
  	void attendClass(Course* course);
  	void exitClass();
  	void graduate(Course* course);
    bool is_subscribed(Course* course);
    std::vector<Course*> get_subscribed_courses() const;
};
