/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:38 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 13:11:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

enum class FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};

class Form {
  protected:
  	FormType _formType;

  public:
    Form(FormType p_formType);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    virtual ~Form();
    virtual void execute() = 0;
};
