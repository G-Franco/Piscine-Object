/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:41:56 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/30 12:04:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/Tool.hpp"
#include "../include/Workshop.hpp"

struct Position {
  int _x;
  int _y;
  int _z;

  Position(int x, int y, int z)
    : _x(x),
      _y(y),
      _z(z) {}
};

struct Statistic {
  int _level;
  int _exp;

  Statistic(int level, int exp)
    : _level(level),
      _exp(exp) {}
};

class Tool;

// Worker class has Position and Statistic attributes as composition.
// Composition is a "has-a" relationship.
class Worker {
  private:
    Position _coordinate;
    Statistic _stat;
    std::vector<Tool *> _tools;
  public:
    Worker();
    Worker(Position pos, Statistic stats);
    Worker(const Worker &copy);
    Worker &operator=(const Worker &copy);
    ~Worker();
    bool check_tools(std::string type) const;
    bool give_tool(Tool *tool);
    void remove_tool(std::string type);
    void sign_up_workshop(Workshop *workshop);
    void leave_workshop(Workshop *workshop);
    void work();
};
