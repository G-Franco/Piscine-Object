/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:19 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 11:29:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "Person.hpp"

class Course;
class Headmaster;

class Student : public Person {
  private:
  	std::vector<std::shared_ptr<Course>> _subscribedCourses;

    Student();

  public:
    Student(std::string name);
    Student(const Student &copy);
    Student &operator=(const Student &copy);
    bool operator==(const Student &other) const;
    bool operator==(const std::string name) const;
    ~Student();
    void choose_class(std::string course_name);
    bool subscribe(std::shared_ptr<Course> &p_course);
    void unsubscribe(std::shared_ptr<Course> &p_course);
  	void attendClass(std::shared_ptr<Course> &course);
  	void exitClass();
  	void graduate(std::shared_ptr<Course> &course);
    bool is_subscribed(std::shared_ptr<Course> &course);
    std::vector<std::shared_ptr<Course>> get_subscribed_courses() const;
};
