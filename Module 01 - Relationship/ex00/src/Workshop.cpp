/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:09:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/06 10:31:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Workshop.hpp"

Workshop::Workshop()
  : _tool_type("Shovel") {
  std::cout << "Workshop default constructor called\n";
}

Workshop::Workshop(std::string tool_type)
  : _tool_type(tool_type) {
  std::cout << "Workshop parameter constructor called\n";
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

std::string Workshop::get_tool_type() const {
  return _tool_type;
}

void Workshop::add_worker(Worker *worker) {
  if (!worker) {
    std::cout << "Worker is NULL\n";
    return;
  }
  if (!worker->GetTool(_tool_type)) {
    std::cout << "Worker does not have the required tool\n";
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
