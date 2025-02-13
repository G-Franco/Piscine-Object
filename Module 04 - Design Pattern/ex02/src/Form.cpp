/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:26:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 17:20:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(FormType p_formType)
  : _formType(p_formType),
    _signed(false),
    _executed(false) {}

Form::Form(const Form &copy)
  : _formType(copy._formType),
    _signed(false),
    _executed(false) {}

Form &Form::operator=(const Form &copy) {
  _formType = copy._formType;
  _signed = copy._signed;
  _executed = copy._executed;
  return *this;
}

Form::~Form() {}

bool Form::check_signed() const {
  return _signed;
}

bool Form::check_executed() const {
  return _executed;
}
