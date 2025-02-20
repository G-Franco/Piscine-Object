/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 17:48:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class Course;

class CourseFinishedForm : public Form {
  private:
    Course *course;
  
  public:
    CourseFinishedForm();
    CourseFinishedForm(const CourseFinishedForm &copy);
    CourseFinishedForm &operator=(const CourseFinishedForm &copy);
    ~CourseFinishedForm();
    void set_course(Course *p_course);
    void sign();
  	void execute();
};
