/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:39:50 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/02 11:29:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Engine.hpp"

Engine::Engine()
  : _engine_state(false) {}

Engine::Engine(const Engine &copy) {
  *this = copy;
}

Engine &Engine::operator=(const Engine &copy) {
  (void)copy;
  _engine_state = false;
  return *this;
}

Engine::~Engine() {}

void Engine::start() {
  if (_engine_state == true) {
    std::cout << "Engine is already on\n";
    return;
  }
  _engine_state = true;
  std::cout << "Engine is now on\n";
}

void Engine::stop() {
  if (_engine_state == false) {
    std::cout << "Engine is already off\n";
    return;
  }
  _engine_state = false;
  std::cout << "Engine is now off\n";
}

bool Engine::get_engine_state() const {
  return _engine_state;
}
