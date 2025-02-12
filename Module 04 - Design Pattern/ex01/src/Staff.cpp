/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:18:06 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:22:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Staff.hpp"

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

Staff::~Staff() {}

void Staff::sign(Form* p_form) {
  if (!p_form) {
    std::cout << "[SIGN] Form is null\n";
    return;
  }
  // TODO: Implement when there is info
  std::cout << "Form signed\n";
}