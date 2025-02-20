/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:16 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 15:29:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include "Course.hpp"

class Course;

class NeedMoreClassRoomForm : public Form {
  private:
    int _classrooms_needed;
    Course *_course;

  public:
    NeedMoreClassRoomForm();
    NeedMoreClassRoomForm(const NeedMoreClassRoomForm &copy);
    NeedMoreClassRoomForm &operator=(const NeedMoreClassRoomForm &copy);
    ~NeedMoreClassRoomForm();
    void set_classrooms_needed(int p_classrooms_needed);
    void set_course(Course *p_course);
    void sign();
  	void execute();
};
