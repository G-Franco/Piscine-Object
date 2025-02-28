/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:40:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 12:06:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Room.hpp"
#include "../include/Person.hpp"
#include "../include/helper.hpp"

long long Room::_ID = 0;

Room::Room()
  : _id(_ID++) {}

Room::Room(const Room &copy)
  : _id(copy._id),
    _occupants(copy._occupants) {}

Room &Room::operator=(const Room &copy) {
  _id = copy._id;
  _occupants = copy._occupants;
  return *this;
}

bool Room::operator==(const Room &other) const {
  return _id == other._id;
}

Room::~Room() {}

void Room::set_self(std::weak_ptr<Room> self) {
  if (self.expired()) {
    std::cout << "[SET SELF] Self pointer is empty\n";
    return;
  }
  this->_self = self;
}

bool Room::canEnter(std::weak_ptr<Person> person) {
  if (person.expired()) {
    std::cout << "[CAN ENTER] Person is null\n";
    return false;
  }
  return true;
}

bool Room::enter(std::weak_ptr<Person> person) {
  if (person.expired()) {
    std::cout << "[ENTER] Person is null\n";
    return false;
  }
  auto person_ptr = person.lock();
  if (canEnter(person)) {
    _occupants.push_back(person);
    person_ptr->set_room(_self);
    return true;
  }
  return false;
}

void Room::exit(std::weak_ptr<Person> person) {
  if (person.expired()) {
    std::cout << "[EXIT] Person is null\n";
    return;
  }
  auto person_ptr = person.lock();
  if (weak_pointer_erase(_occupants, person)) {
    person_ptr->set_room(std::weak_ptr<Room>());
  }
  else {
    std::cout << "[EXIT] Person not found\n";
  }
}

void Room::printOccupant() {
  std::cout << "Room " << _id << " occupants:\n";
  for (auto occupant : _occupants) {
    if (occupant.expired()) {
      continue;
    }
    auto occupant_ptr = occupant.lock();
    std::cout << occupant_ptr->get_name() << "\n";
  }
}

long long Room::get_id() const {
  return _id;
}

bool Room::is_empty() const {
  return _occupants.empty();
}
