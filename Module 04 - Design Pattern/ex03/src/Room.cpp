/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:40:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 11:54:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Room.hpp"
#include "../include/Person.hpp"

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

bool Room::canEnter(std::shared_ptr<Person> person) {
  if (!person) {
    std::cout << "[CAN ENTER] Person is null\n";
    return false;
  }
  return true;
}

bool Room::enter(std::shared_ptr<Person> person) {
  if (!person) {
    std::cout << "[ENTER] Person is null\n";
    return false;
  }
  if (canEnter(person)) {
    _occupants.push_back(person);
    person->set_room(this);
    return true;
  }
  return false;
}

void Room::exit(std::shared_ptr<Person> person) {
  if (!person) {
    std::cout << "[EXIT] Person is null\n";
    return;
  }
  std::vector<std::shared_ptr<Person> >::iterator it = std::find(_occupants.begin(), _occupants.end(), person);
  if (it != _occupants.end()) {
    _occupants.erase(it);
    person->set_room(nullptr);
  }
  else {
    std::cout << "[EXIT] Person not found\n";
  }
}

void Room::printOccupant() {
  std::cout << "Room " << _id << " occupants:\n";
  for (std::vector<std::shared_ptr<Person> >::iterator it = _occupants.begin(); it != _occupants.end(); it++) {
    std::cout << (*it)->get_name() << "\n";
  }
}

long long Room::get_id() const {
  return _id;
}

bool Room::is_empty() const {
  return _occupants.empty();
}
