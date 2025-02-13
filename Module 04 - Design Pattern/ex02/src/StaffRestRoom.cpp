/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaffRestRoom.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:35:03 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/StaffRestRoom.hpp"

StaffRestRoom::StaffRestRoom()
  : Room() {}

StaffRestRoom::StaffRestRoom(const StaffRestRoom &copy)
  : Room(copy) {}

StaffRestRoom &StaffRestRoom::operator=(const StaffRestRoom &copy) {
  _id = copy._id;
  return *this;
}

bool StaffRestRoom::operator==(const StaffRestRoom &other) const {
  return _id == other._id;
}

StaffRestRoom::~StaffRestRoom() {}
