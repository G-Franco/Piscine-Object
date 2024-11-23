/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:44:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/23 10:48:15 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

#define FORMATTING std::string("Error: Bad formatting\nUse \"x,y\" to define points\n")
#define FILE_DIR std::string("../files/")

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
    void validate_input(int ac, char **av);
    void print_graph();
    void add_point(float xf, float yf);
    void display_points() const;
    std::vector<Vector2> read_points_from_file(const std::string &filename);
};
