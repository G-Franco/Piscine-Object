/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:55:03 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/11 16:21:59 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"

Worker::Worker()
  : _coordinate(Position(0, 0, 0)),
    _stat(Statistic(0, 0)),
    _shovel(NULL) {
  std::cout << "Worker default constructor called\n";    
}

Worker::Worker(Position pos, Statistic stats)
  : _coordinate(pos),
    _stat(stats),
    _shovel(NULL) {
  std::cout << "Worker parametric constructor called\n";
}

Worker::Worker(const Worker &copy)
  : _coordinate(copy._coordinate),
    _stat(copy._stat),
    _shovel(NULL) {
  std::cout << "Worker copy constructor called\n";
}

Worker &Worker::operator=(const Worker &worker) {
  std::cout << "Worker copy assignment operator called\n";
  _coordinate = worker._coordinate;
  _stat = worker._stat;
  _shovel = NULL;
  return *this;
}

Worker::~Worker() {
  std::cout << "Worker destructor called\n";
  _shovel->assign_worker(NULL);
}

bool Worker::give_shovel(Shovel *shovel) {
  if (_shovel) {
    std::cout << "Worker already has a shovel\n";
    return false;
  }
  if (!shovel) {
    std::cout << "Shovel is NULL\n";
    return false;
  }
  _shovel = shovel;
  std::cout << "Worker has been given a shovel\n";
  return true;
}

void Worker::remove_shovel() {
  if (!_shovel) {
    std::cout << "Worker does not have a shovel\n";
    return;
  }
  _shovel = NULL;
  std::cout << "The shovel has been removed from the worker\n";
}