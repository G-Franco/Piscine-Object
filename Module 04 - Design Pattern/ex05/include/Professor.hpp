/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 15:30:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "Staff.hpp"

class Course;
class Student;

class Professor : public Staff {
  private:
    std::weak_ptr<Course> _currentCourse;
    std::vector<std::weak_ptr<Student>> _graduation_requests;

    Professor();

  public:
    Professor(std::string name);
    Professor(const Professor &copy);
    Professor &operator=(const Professor &copy);
    bool operator==(const Professor &other) const;
    bool operator==(const std::string name) const;
    ~Professor();
    void request_course(std::string course_name);
    void request_graduation(std::weak_ptr<Student> &student);
  	void assignCourse(std::weak_ptr<Course> &course);
  	void closeCourse();
  	void doClass();
    std::weak_ptr<Course> get_current_course() const;
    void course_graduation_request(std::weak_ptr<Student> &student);
    void check_graduation_requests();
    void on_ring(Event event) override;
};
