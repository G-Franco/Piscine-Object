/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:10:17 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/11 16:23:18 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Shovel.hpp"
#include <iostream>
#include <sstream>

Shovel::Shovel()
  : _numberOfUses(DEFAULT_USES),
    _worker(NULL) {
  std::cout << "Shovel default constructor called\n";
}

Shovel::Shovel(int uses)
  : _numberOfUses(uses),
    _worker(NULL) {
  if (uses < 0) {
    throw std::runtime_error("Number of uses cannot be negative");    
  }
  if (uses > MAX_USES) {
    std::stringstream err;
    err << "Number of uses cannot exceed " << MAX_USES;
    throw std::runtime_error(err.str());
  }
  std::cout << "Shovel parametric constructor called\n";
}

Shovel::Shovel(const Shovel &copy)
  : _numberOfUses(copy._numberOfUses),
    _worker(NULL) {
  std::cout << "Shovel copy constructor called\n";
}

Shovel &Shovel::operator=(const Shovel &shovel) {
  std::cout << "Shovel copy assignment operator called\n";
  _numberOfUses = shovel._numberOfUses;
  _worker = NULL;
  return *this;
}

Shovel::~Shovel() {
  std::cout << "Shovel destructor called\n";
  _worker->remove_shovel();
}

// Assigns a worker to the shovel.
// Can be used to clear the worker from the shovel by passing NULL.
void Shovel::assign_worker(Worker *worker) {
  if (_worker) {
    _worker->remove_shovel();
  }
  if (worker && worker->give_shovel(this)) {
    _worker = worker;
    return;
  }
  _worker = NULL;
  std::cout << "Shovel currently has no worker\n";
}

void Shovel::use() {
  if (_numberOfUses == 0) {
    std::cout << "Shovel is broken\n";
    return;
  }
  _numberOfUses--;
  std::cout << "Shovel used, " << _numberOfUses << " uses left\n";
}