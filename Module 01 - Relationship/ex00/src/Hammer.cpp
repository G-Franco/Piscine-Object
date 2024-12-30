/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:40:59 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/30 11:30:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Hammer.hpp"

Hammer::Hammer()
  : Tool() {
  std::cout << "Hammer default constructor called\n";
}

Hammer::Hammer(int uses)
  : Tool(uses) {
  std::cout << "Hammer parametric constructor called\n";
  if (uses > HAMMER_MAX_USES) {
    std::stringstream err;
    err << "Number of uses for a hammer cannot exceed " << HAMMER_MAX_USES;
    throw std::runtime_error(err.str());
  }
}

Hammer::Hammer(const Hammer &copy)
  : Tool(copy) {
  std::cout << "Hammer copy constructor called\n";
}

Hammer &Hammer::operator=(const Hammer &hammer) {
  (void)hammer;
  std::cout << "Hammer copy assignment operator called\n";
  return *this;
}

Hammer::~Hammer() {
  std::cout << "Hammer destructor called\n";
  _worker->remove_tool(get_type());
}

void Hammer::use() {
  if (_numberOfUses == 0) {
    std::cout << "Hammer is broken\n";
    return;
  }
  _numberOfUses--;
  std::cout << "Hammer used, " << _numberOfUses << " uses left\n";
}

std::string Hammer::get_type() const {
  return "Hammer";
}
