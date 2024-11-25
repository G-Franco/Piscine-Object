/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:44:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/25 15:20:56 by gacorrei         ###   ########.fr       */
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
#define FILE_DIR std::string("files/")
#define MAX_SIZE 10

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
        bool operator==(const Vector2 &rhs) const;
        ~Vector2();
        const float &getX() const;
        const float &getY() const;
    };

    Vector2 _size;
    std::vector<Vector2> _points;
    std::vector<std::string> _graph;
    void build_graph();
    void validate_input(int ac, char **av);

  public:
    Graph();
    Graph(float width, float height, int ac, char **av);
    Graph(const Graph &copy);
    Graph &operator=(const Graph &copy);
    ~Graph();
    void print_graph();
    void add_point(float xf, float yf);
    void display_points() const;
    std::vector<Vector2> read_points_from_file(const std::string &filename);
};
