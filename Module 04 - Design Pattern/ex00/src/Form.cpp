/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:26:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:27:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(FormType p_formType)
  : _formType(p_formType) {}

Form::Form(const Form &copy)
  : _formType(copy._formType) {}

Form &Form::operator=(const Form &copy) {
  _formType = copy._formType;
  return *this;
}

Form::~Form() {}
