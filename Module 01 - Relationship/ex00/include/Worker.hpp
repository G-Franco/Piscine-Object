/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:41:56 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/11 16:12:18 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "../include/Shovel.hpp"

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

class Shovel;

// Worker class has Position and Statistic attributes as composition.
// Composition is a "has-a" relationship.
class Worker {
  private:
    Position _coordinate;
    Statistic _stat;
    Shovel *_shovel;
  public:
    Worker();
    Worker(Position pos, Statistic stats);
    Worker(const Worker &copy);
    Worker &operator=(const Worker &copy);
    ~Worker();
    bool give_shovel(Shovel *shovel);
    void remove_shovel();
};
