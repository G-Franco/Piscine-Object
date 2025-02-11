/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Courtyard.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:06:43 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:10:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Courtyard.hpp"

Courtyard::Courtyard() 
  : Room() {}

Courtyard::Courtyard(const Courtyard &copy)
  : Room(copy) {}

Courtyard &Courtyard::operator=(const Courtyard &copy) {
  (void)copy;
  return *this;
}

Courtyard::~Courtyard() {}
