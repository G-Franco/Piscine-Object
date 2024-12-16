/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:13:24 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/16 11:30:49 by gacorrei         ###   ########.fr       */
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

// Assigns a worker to the tool.
// Can be used to clear the worker from the tool by passing NULL.
void Tool::assign_worker(Worker *worker) {
  if (_worker) {
    _worker->remove_tool(get_type());
  }
  if (worker && worker->give_tool(this)) {
    _worker = worker;
    return;
  }
  _worker = NULL;
  std::cout << get_type() << " currently has no worker\n";
}
