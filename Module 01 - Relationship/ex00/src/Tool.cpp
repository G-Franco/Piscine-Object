/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:13:24 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 14:24:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Tool.hpp"

Tool::Tool()
  : _numberOfUses(DEFAULT_USES),
    _worker(NULL) {
   std::cout << "Tool default constructor called\n";    
}

Tool::Tool(int uses)
  : _numberOfUses(uses),
    _worker(NULL) {
   std::cout << "Tool parametric constructor called\n";    
   if (uses < 0) {
      throw std::runtime_error("Number of uses cannot be negative");    
   }
}

Tool::Tool(const Tool &copy)
  : _numberOfUses(copy._numberOfUses),
    _worker(NULL) {
   std::cout << "Tool copy constructor called\n";    
}

Tool &Tool::operator=(const Tool &copy) {
   std::cout << "Tool copy assignment operator called\n";
   _numberOfUses = copy._numberOfUses;
   _worker = NULL;
   return *this;
}

Tool::~Tool() {
   std::cout << "Tool destructor called\n";    
}

int Tool::get_number_of_uses() const {
   return _numberOfUses;
}

Worker *Tool::get_worker() const {
   return _worker;
}

// Assigns a worker to the tool.
// Can be used to clear the worker from the tool by passing NULL.
void Tool::assign_worker(Worker *worker) {
  _worker = worker;
  if (!_worker) {
    std::cout << get_type() << " currently has no worker\n";
  }
}
