/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:12:04 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:15:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Person.hpp"

Person::Person()
  : _name(""),
    _currentRoom(NULL) {}

Person::Person(std::string p_name)
  : _name(p_name),
    _currentRoom(NULL) {}

Person::Person(const Person &copy)
  : _name(copy._name),
    _currentRoom(copy._currentRoom) {}

Person &Person::operator=(const Person &copy) {
  _name = copy._name;
  _currentRoom = copy._currentRoom;
  return *this;
}

Person::~Person() {}

Room *Person::room() {
  return _currentRoom;
}

std::string Person::get_name() const {
  return _name;
}
