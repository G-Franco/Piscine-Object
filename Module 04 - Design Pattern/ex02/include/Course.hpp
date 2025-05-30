/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 14:29:16 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Professor.hpp"

class Student;
class Professor;

class Course {
  private:
  	std::string _name;
  	Professor* _responsible;
  	std::vector<Student*> _students;
  	int _numberOfClassToGraduate;
  	int _maximumNumberOfStudent;

    Course();
    
    public:
  	Course(std::string p_name);
    Course(const Course &copy);
    Course &operator=(const Course &copy);
    bool operator==(const Course &other);
    ~Course();
  	void assign(Professor* p_professor);
  	void subscribe(Student* p_student);
    std::string get_name() const;
};
