/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:00:54 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 15:06:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bell.hpp"
#include "../include/Professor.hpp"
#include "../include/Student.hpp"
#include "../include/observer.hpp"
#include "../include/helper.hpp"

Bell::Bell() {}

Bell::~Bell() {}

void Bell::ring(Event event) {
  std::cout << "\nBell is ringing\n";
  for (const auto &observer : _observers)
  {
    if (auto target = observer.lock()) {
      target->on_ring(event);
    }
  }
}

// Given that the classroom entering logic relies on professors to enter first
// and students to enter last, we need to add professors to the front of the
// vector and students to the back, so that the ring function can iterate
// through the observers in the correct order.
void Bell::add_observer(std::weak_ptr<IObserver> &observer) {
  if (observer.expired() ||
      weak_pointer_find(_observers, observer)) {
    return;
  }
  auto target = observer.lock();
  if (std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(target)) {
    _observers.insert(_observers.begin(), observer);
  }
  else if (std::shared_ptr<Student> student = std::dynamic_pointer_cast<Student>(target)) {
    _observers.push_back(observer);
  }
}

void Bell::remove_observer(std::weak_ptr<IObserver> &observer) {
  if (observer.expired()) {
    return;
  }
  for (auto it = _observers.begin(); it != _observers.end();) {
    if (it->expired()) {
      it = _observers.erase(it);
    }
    else if (it->lock() == observer.lock()) {
      _observers.erase(it);
      return;
    }
    else {
      ++it;
    }
  }
}
