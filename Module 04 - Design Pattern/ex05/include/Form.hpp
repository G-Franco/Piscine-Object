/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:38 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:22:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>

enum class FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};

class Form {
  protected:
  	FormType _formType;
    bool _signed;
    bool _executed;

  public:
    Form(FormType p_formType);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    ~Form();
    virtual void sign() = 0;
    virtual void execute() = 0;
    bool check_signed() const;
    bool check_executed() const;
};
