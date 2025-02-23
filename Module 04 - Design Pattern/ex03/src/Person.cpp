/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:12:04 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:21:25 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Person.hpp"
#include "../include/Room.hpp"
#include "../include/Headmaster.hpp"

Person::Person()
  : _name(""),
    _currentRoom(NULL),
    _headmaster(NULL) {}

Person::Person(std::string p_name)
  : _name(p_name),
    _currentRoom(NULL),
    _headmaster(NULL) {}

Person::Person(const Person &copy)
  : std::enable_shared_from_this<Person>(),
    _name(copy._name),
    _currentRoom(copy._currentRoom),
    _headmaster(copy._headmaster) {}

Person &Person::operator=(const Person &copy) {
  _name = copy._name;
  _currentRoom = copy._currentRoom;
  _headmaster = copy._headmaster;
  return *this;
}

Person::~Person() {}

Room *Person::room() {
  return _currentRoom;
}

void Person::set_room(Room *p_room) {
  _currentRoom = p_room;
}

void Person::set_headmaster(Headmaster *headmaster) {
  _headmaster = headmaster;
}

std::string Person::get_name() const {
  return _name;
}
