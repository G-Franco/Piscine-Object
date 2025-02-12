/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 10:27:18 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Course.hpp"

class Course;

class Classroom : public Room {
  private:
  	Course* _course;

  public:
  	Classroom();
    Classroom(const Classroom &copy);
    Classroom &operator=(const Classroom &copy);
    ~Classroom();
  	void assignCourse(Course* p_course);
    Course* getCourse() const;
};
