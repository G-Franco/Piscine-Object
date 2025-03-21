/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:55:03 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/08 10:02:17 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"

Worker::Worker()
  : _coordinate(Position(0, 0, 0)),
    _stat(Statistic(0, 0)) {
  std::cout << "Worker default constructor called\n";    
}

Worker::Worker(Position pos, Statistic stats)
  : _coordinate(pos),
    _stat(stats) {
  std::cout << "Worker parametric constructor called\n";
}

Worker::Worker(const Worker &copy)
  : _coordinate(copy._coordinate),
    _stat(copy._stat) {
  std::cout << "Worker copy constructor called\n";
}

Worker &Worker::operator=(const Worker &worker) {
  std::cout << "Worker copy assignment operator called\n";
  _coordinate = worker._coordinate;
  _stat = worker._stat;
  return *this;
}

Worker::~Worker() {
  std::cout << "Worker destructor called\n";
  for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it) {
    (*it)->assign_worker(NULL);
  }
}

Tool *Worker::GetTool(std::string ToolType) const {
  for (std::vector<Tool *>::const_iterator it = _tools.begin(); it != _tools.end(); ++it) {
    if ((*it)->get_type() == ToolType) {
      return *it;
    }
  }
  return NULL;
}

bool Worker::give_tool(Tool *tool) {
  if (!tool) {
    std::cout << "Tool is NULL\n";
    return false;
  }
  std::string type = tool->get_type();
  if (GetTool(type)) {
    std::cout << "Worker already has a " << type << "\n";
    return false;
  }
  Worker *previous_worker = tool->get_worker();
  if (previous_worker) {
    previous_worker->remove_tool(type);
  }
  _tools.push_back(tool);
  tool->assign_worker(this);
  std::cout << "Worker has been given a " << type << "\n";
  return true;
}

void Worker::remove_tool(std::string type) {
  if (!GetTool(type)) {
    std::cout << "Worker does not have a " << type << "\n";
    return;
  }
  for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it) {
    if ((*it)->get_type() == type) {
      (*it)->assign_worker(NULL);
      _tools.erase(it);
      break;
    }
  }
  for (size_t i = 0; i < _workshops.size(); i++) {
      if (_workshops[i]->get_tool_type() == type)
      {
        leave_workshop(_workshops[i]);
        i--;
      }
  }
  std::cout << "The " << type << " has been removed from the worker\n";
}

void Worker::sign_up_workshop(Workshop *workshop) {
  if (!workshop) {
    std::cout << "Workshop is NULL\n";
    return;
  }
  if (!GetTool(workshop->get_tool_type())) {
    std::cout << "Worker does not have the required tool\n";
    return;
  }
  if (!workshop->add_worker(this)) {
    std::cout << "Worker could not sign up for the workshop\n";
    return;
  }
  _workshops.push_back(workshop);
  std::cout << "Worker has signed up for the workshop\n";
}

void Worker::leave_workshop(Workshop *workshop) {
  if (!workshop) {
    std::cout << "Workshop is NULL\n";
    return;
  }
  workshop->remove_worker(this);
  std::vector<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);
  if (it != _workshops.end()) {
    _workshops.erase(it);
  }
  std::cout << "Worker has left the workshop\n";
}

bool Worker::work(std::string tool_type) {
  std::cout << "Worker is working\n";
  for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it) {
    if ((*it)->get_type() == tool_type) {
      (*it)->use();
      if ((*it)->get_number_of_uses() == 0) {
        std::cout << "Worker has broken the " << tool_type << "\n";
        remove_tool(tool_type);
        return false;
      }
    }
  }
  return true;
}
