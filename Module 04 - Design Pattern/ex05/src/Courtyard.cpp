/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Courtyard.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:06:43 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:33:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Courtyard.hpp"

Courtyard::Courtyard() 
  : Room() {}

Courtyard::Courtyard(const Courtyard &copy)
  : Room(copy) {}

Courtyard &Courtyard::operator=(const Courtyard &copy) {
  _id = copy._id;
  return *this;
}

bool Courtyard::operator==(const Courtyard &other) const {
  return _id == other._id;
}

Courtyard::~Courtyard() {}
