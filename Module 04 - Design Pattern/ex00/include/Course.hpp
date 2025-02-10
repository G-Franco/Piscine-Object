/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:42:48 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Professor.hpp"

// TODO: DON'T FORGET TO CHECK WHERE RINGBELL GOES
// TODO: ARE THESE NECESSARY?
class Student;
class Professor;

class Course {
  private:
  	std::string _name;
  	Professor* _responsible;
  	std::vector<Student*> _students;
  	int _numberOfClassToGraduate;
  	int _maximumNumberOfStudent;

  public:
  	Course(std::string p_name);
  	void assign(Professor* p_professor);
  	void subscribe(Student* p_student);
};
