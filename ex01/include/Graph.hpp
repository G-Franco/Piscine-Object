/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:44:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/15 11:12:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <sstream>

class Graph {
  private:
    class Vector2 {
      private:
        float _x;
        float _y;
        
      public:
        Vector2();
        Vector2(float x, float y);
        Vector2(const Vector2 &copy);
        Vector2 &operator=(const Vector2 &copy);
        ~Vector2();
        const float &getX() const;
        const float &getY() const;
        void setX(float x);
        void setY(float y);
    };

    Vector2 _size;
    std::vector<Vector2> _points;
    std::vector<std::string> _graph;
    void build_graph();

  public:
    Graph();
    Graph(float width, float height);
    Graph(const Graph &copy);
    Graph &operator=(const Graph &copy);
    ~Graph();
    void print_graph();
    void add_point(float xf, float yf);
    void display_points() const;
};
