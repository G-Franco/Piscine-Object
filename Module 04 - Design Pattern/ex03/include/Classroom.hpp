/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 11:55:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class Course;

class Classroom : public Room {
  private:
  	std::shared_ptr<Course> _course;

  public:
  	Classroom();
    Classroom(const Classroom &copy);
    Classroom &operator=(const Classroom &copy);
    bool operator==(const Classroom &other) const;
    ~Classroom();
    bool canEnter(std::shared_ptr<Person> person);
  	void assignCourse(std::shared_ptr<Course> course);
    std::shared_ptr<Course> getCourse() const;
};
