/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:12:04 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/28 16:54:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Person.hpp"
#include "../include/Room.hpp"
#include "../include/Headmaster.hpp"

Person::Person()
  : _name(""),
    _currentRoom(std::weak_ptr<Room>()),
    _headmaster(NULL) {}

Person::Person(std::string p_name)
  : _name(p_name),
    _currentRoom(std::weak_ptr<Room>()),
    _headmaster(NULL) {}

Person::Person(const Person &copy)
  : _name(copy._name),
    _currentRoom(copy._currentRoom),
    _headmaster(copy._headmaster) {}

Person &Person::operator=(const Person &copy) {
  _name = copy._name;
  _currentRoom = copy._currentRoom;
  _headmaster = copy._headmaster;
  return *this;
}

Person::~Person() {}

std::weak_ptr<Room> &Person::room() {
  return _currentRoom;
}

void Person::set_self(std::weak_ptr<Person> self) {
  if (self.expired()) {
    std::cout << "[SET SELF] Self pointer is empty\n";
    return;
  }
  _self = self;
}

void Person::set_room(std::weak_ptr<Room> room) {
  _currentRoom = room;
}

void Person::set_headmaster(Headmaster *headmaster) {
  if (!headmaster) {
    std::cout << "[SET HEADMASTER] Headmaster is empty\n";
    return;
  }
  _headmaster = headmaster;
}

std::string Person::get_name() const {
  return _name;
}

bool Person::exit_room() {
  if (_currentRoom.expired()) {
    std::cout << "[EXIT ROOM] Person is not in a room\n";
    return false;
  }
  auto room = _currentRoom.lock();
  room->exit(_self);
  set_room(std::weak_ptr<Room>());
  return true;
}

void Person::on_ring(Event event) {
  (void)event;
}
