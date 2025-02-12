/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:29:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:35:42 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Headmaster.hpp"

Headmaster::Headmaster(std::string p_name)
  : Staff(p_name) {}

Headmaster::Headmaster(const Headmaster &copy)
  : Staff(copy),
    _formToValidate(copy._formToValidate) {}

Headmaster &Headmaster::operator=(const Headmaster &copy) {
  _formToValidate = copy._formToValidate;
  return *this;
}

Headmaster::~Headmaster() {}

void Headmaster::receiveForm(Form* p_form) {
  if (!p_form) {
    std::cout << "[RECEIVE FORM] Form is null\n";
    return;
  }
  _formToValidate.push_back(p_form);
  std::cout << "Form received\n";
}
