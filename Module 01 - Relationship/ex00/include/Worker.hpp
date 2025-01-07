/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:41:56 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 11:48:18 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Workshop.hpp"
#include "Tool.hpp"

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
class Workshop;

// Worker class has Position and Statistic attributes as composition.
// Composition is a "has-a" relationship.
class Worker {
  private:
    Position _coordinate;
    Statistic _stat;
    std::vector<Tool *> _tools;
    std::vector<Workshop *> _workshops;
  public:
    Worker();
    Worker(Position pos, Statistic stats);
    Worker(const Worker &copy);
    Worker &operator=(const Worker &copy);
    ~Worker();
    Tool *GetTool(std::string ToolType) const;
    bool give_tool(Tool *tool);
    void remove_tool(std::string type);
    void sign_up_workshop(Workshop *workshop);
    void leave_workshop(Workshop *workshop);
    bool work(std::string tool_type);
};
