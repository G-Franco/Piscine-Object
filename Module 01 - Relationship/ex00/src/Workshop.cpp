/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:09:01 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/30 12:05:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Workshop.hpp"

Workshop::Workshop() {
  std::cout << "Workshop default constructor called\n";
}

Workshop::Workshop(const Workshop &copy) {
  std::cout << "Workshop copy constructor called\n";
  *this = copy;
}

Workshop &Workshop::operator=(const Workshop &copy) {
  std::cout << "Workshop assignation operator called\n";
  if (this != &copy) {
    _workers = copy._workers;
  }
  return *this;
}

Workshop::~Workshop() {
  std::cout << "Workshop destructor called\n";
}

void Workshop::add_worker(Worker *worker) {
  if (!worker) {
    std::cout << "Worker is NULL\n";
    return;
  }
  _workers.push_back(worker);
}

void Workshop::remove_worker(Worker *worker) {
  if (!worker) {
    std::cout << "Worker is NULL\n";
    return;
  }
  std::vector<Worker *>::iterator it = std::find(_workers.begin(), _workers.end(), worker);
  if (it != _workers.end()) {
    _workers.erase(it);
  }
}

void Workshop::executeWorkDay() {
  for (std::vector<Worker *>::iterator it = _workers.begin(); it != _workers.end(); ++it) {
    (*it)->work();
  }
}
