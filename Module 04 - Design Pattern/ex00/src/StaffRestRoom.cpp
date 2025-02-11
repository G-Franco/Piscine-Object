/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaffRestRoom.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:05:25 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StaffRestRoom.hpp"

StaffRestRoom::StaffRestRoom()
  : Room() {}

StaffRestRoom::StaffRestRoom(const StaffRestRoom &copy)
  : Room(copy) {}

StaffRestRoom &StaffRestRoom::operator=(const StaffRestRoom &copy) {
  (void)copy;
  return *this;
}

StaffRestRoom::~StaffRestRoom() {}
