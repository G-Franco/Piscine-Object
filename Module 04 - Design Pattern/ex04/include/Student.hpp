/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:19 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 10:37:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "Person.hpp"

class Course;
class Headmaster;

class Student : public Person {
  private:
  std::weak_ptr<Student> _self;
  	std::vector<std::weak_ptr<Course> > _subscribedCourses;

    Student();

  public:
    Student(std::string name);
    Student(const Student &copy);
    Student &operator=(const Student &copy);
    bool operator==(const Student &other) const;
    bool operator==(const std::string name) const;
    ~Student();
    void set_self(std::weak_ptr<Student> self);
    void choose_class(std::string course_name);
    bool subscribe(std::weak_ptr<Course> &course);
    void unsubscribe(std::weak_ptr<Course> &course);
  	void attendClass(std::weak_ptr<Course> &course);
  	void exitClass();
  	void graduate(std::weak_ptr<Course> &course);
    bool is_subscribed(std::weak_ptr<Course> &course);
    std::vector<std::weak_ptr<Course>> get_subscribed_courses() const;
};
