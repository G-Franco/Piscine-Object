/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 11:57:18 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class Course;

class CourseFinishedForm : public Form {
  private:
    std::weak_ptr<Course> _course;
  
  public:
    CourseFinishedForm();
    CourseFinishedForm(const CourseFinishedForm &copy);
    CourseFinishedForm &operator=(const CourseFinishedForm &copy);
    ~CourseFinishedForm();
    void set_course(std::weak_ptr<Course> course);
    void sign();
  	void execute();
};
