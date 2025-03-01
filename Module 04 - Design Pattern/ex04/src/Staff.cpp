/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:18:06 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/28 16:43:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Staff.hpp"
#include "../include/Form.hpp"

Staff::Staff()
  : Person("") {}

Staff::Staff(std::string p_name)
  : Person(p_name) {}

Staff::Staff(const Staff &copy)
  : Person(copy) {}

Staff &Staff::operator=(const Staff &copy) {
  (void)copy;
  return *this;
}

bool Staff::operator==(const Staff &other) const {
  return _name == other._name;
}

Staff::~Staff() {}

void Staff::sign(std::shared_ptr<Form> p_form) {
  if (!p_form) {
    std::cout << "[SIGN] Form is null\n";
    return;
  }
  p_form.get()->sign();
  std::cout << "Form signed\n";
}

void Staff::on_ring(Event event) {
  (void)event;
}
