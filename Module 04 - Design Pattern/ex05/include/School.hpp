/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   School.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:24:41 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 18:14:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <vector>
#include "Headmaster.hpp"

class Secretary;
class Professor;
class Student;
class Course;

class School {
  private:
    Headmaster _headmaster;

    School(const School &copy);
    School operator=(const School &copy);

  public:
    School();
    ~School();
    void runDayRoutine();
    void launchClasses();
    void requestRingBell();
    void recruteProfessor(std::string name);
    void recruteStudent(std::string name);
    std::weak_ptr<Course> getCourse(std::string name);
    std::vector<std::weak_ptr<Student>> getStudents();
    std::vector<std::weak_ptr<Professor>> getProfessors();
    Headmaster getHeadmaster();
    Secretary getSecretary();
    void graduationCeremony();
};
