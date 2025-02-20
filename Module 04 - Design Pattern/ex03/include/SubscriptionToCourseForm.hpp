/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 15:30:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include "Course.hpp"

class Course;

class SubscriptionToCourseForm : public Form {
  private:
    Course *_course;
  
  public:
    SubscriptionToCourseForm();
    SubscriptionToCourseForm(const SubscriptionToCourseForm &copy);
    SubscriptionToCourseForm &operator=(const SubscriptionToCourseForm &copy);
    ~SubscriptionToCourseForm();
    void set_course(Course *course);
    void sign();
  	void execute();
};
