/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 12:11:29 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class Course;

class CourseFinishedForm : public Form {
  private:
    std::shared_ptr<Course> course;
  
  public:
    CourseFinishedForm();
    CourseFinishedForm(const CourseFinishedForm &copy);
    CourseFinishedForm &operator=(const CourseFinishedForm &copy);
    ~CourseFinishedForm();
    void set_course(std::shared_ptr<Course> p_course);
    void sign();
  	void execute();
};
