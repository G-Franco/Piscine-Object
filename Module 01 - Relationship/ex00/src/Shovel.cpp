/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:10:17 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 12:08:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Shovel.hpp"

Shovel::Shovel()
  : Tool() {
  std::cout << "Shovel default constructor called\n";
}

Shovel::Shovel(int uses)
  : Tool(uses) {
  std::cout << "Shovel parametric constructor called\n";
  if (uses > SHOVEL_MAX_USES) {
    std::stringstream err;
    err << "Number of uses for a shovel cannot exceed " << SHOVEL_MAX_USES;
    throw std::runtime_error(err.str());
  }
}

Shovel::Shovel(const Shovel &copy)
  : Tool(copy) {
  std::cout << "Shovel copy constructor called\n";
}

Shovel &Shovel::operator=(const Shovel &shovel) {
  (void)shovel;
  std::cout << "Shovel copy assignment operator called\n";
  return *this;
}

Shovel::~Shovel() {
  std::cout << "Shovel destructor called\n";
  if (_worker) {
    _worker->remove_tool(get_type());
  }
}

void Shovel::use() {
  if (_numberOfUses == 0) {
    std::cout << "Shovel is broken\n";
    return;
  }
  _numberOfUses--;
  std::cout << "Shovel used, " << _numberOfUses << " uses left\n";
}

std::string Shovel::get_type() const {
  return "Shovel";
}