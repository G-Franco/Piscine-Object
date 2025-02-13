/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:29:00 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 16:32:37 by gacorrei         ###   ########.fr       */
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

void Headmaster::receiveForm(std::shared_ptr<Form> p_form) {
  if (!p_form) {
    std::cout << "[RECEIVE FORM] Form is null\n";
    return;
  }
  _formToValidate.push_back(p_form);
  std::cout << "Form received\n";
}

void Headmaster::sign_form(std::shared_ptr<Form> form) {
  if (!form) {
    std::cout << "[SIGN FORM] Form is null\n";
    return;
  }
  if (std::find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end()) {
    std::cout << "[SIGN FORM] Form not received\n";
    return;
  }
  form.get()->sign();
}

void Headmaster::execute_form(std::shared_ptr<Form> form) {
  if (!form) {
    std::cout << "[EXECUTE FORM] Form is null\n";
    return;
  }
  if (std::find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end()) {
    std::cout << "[EXECUTE FORM] Form not received\n";
    return;
  }
  form.get()->execute();
}

void Headmaster::sign_all_forms() {
  for (auto &form : _formToValidate) {
    form.get()->sign();
  }
}

void Headmaster::execute_all_forms() {
  for (auto &form : _formToValidate) {
    form.get()->execute();
  }
}

// To archive the correct forms and remove them from the vector
// in a single loop we need to use the erase-remove idiom:
// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
// In short, remove_if places the elements that should be removed at the end of 
// the vector and returns an iterator to the first of those elements.
// We then use erase to remove those elements from the vector.
// A lambda function is used to check if the form has been executed.
// Lambda function: [captured variable](parameters) {function body}
void Headmaster::clean_forms(Secretary &secretary) {
  _formToValidate.erase(
    std::remove_if(
      _formToValidate.begin(),
      _formToValidate.end(),
      [&secretary](std::shared_ptr<Form> &form) {
        if (form.get()->check_executed()) {
          secretary.archiveForm(form);
          return true;
        }
        return false;
      }),
    _formToValidate.end());
}
