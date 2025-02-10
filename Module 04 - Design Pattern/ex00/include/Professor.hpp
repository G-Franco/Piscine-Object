/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:39:41 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"

class Professor : public Staff {
  private:
  	Course* _currentCourse;
  
  public:
  	void assignCourse(Course* p_course);
  	void doClass();
  	void closeCourse();
};
