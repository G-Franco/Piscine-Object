/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:41:56 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/16 11:27:20 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include "../include/Tool.hpp"

struct Position {
  int x;
  int y;
  int z;

  Position(int x, int y, int z)
    : x(x),
      y(y),
      z(z) {}
};

struct Statistic {
  int level;
  int exp;

  Statistic(int level, int exp)
    : level(level),
      exp(exp) {}
};

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
};
