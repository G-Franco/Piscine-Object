/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 12:00:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class Course;

class SubscriptionToCourseForm : public Form {
  private:
    std::weak_ptr<Course> _course;
  
  public:
    SubscriptionToCourseForm();
    SubscriptionToCourseForm(const SubscriptionToCourseForm &copy);
    SubscriptionToCourseForm &operator=(const SubscriptionToCourseForm &copy);
    ~SubscriptionToCourseForm();
    void set_course(std::weak_ptr<Course> &course);
    void sign();
  	void execute();
};
