/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:47:43 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/14 12:08:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

Graph::Graph()
  : _size(1, 1) {
    build_graph();
  }

Graph::Graph(float width, float height)
  : _size(width, height) {
    if (_size.getX() < 1 || _size.getY() < 1) {
      throw (std::runtime_error("Graph size must be positive\n"));
    }
    if (_size.getX() > 100 || _size.getY() > 100) {
      throw (std::runtime_error("Graph size cannot exceed 100\n"));
    }
    build_graph();
  }

Graph::Graph(const Graph &copy)
  : _size(copy._size), _points(copy._points), _graph(copy._graph) {}

Graph &Graph::operator=(const Graph &copy) {
  if (this != &copy) {
    _size = copy._size;
    _points = copy._points;
    _graph = copy._graph;
  }
  return *this;
}

Graph::~Graph() {}

void Graph::build_graph() {
  int width = _size.getX();
  int height = _size.getY();
  int spacing = 2;
  std::string line;
  for (int i = 0; i < width; i++) {
    line += "  .";
  }
  std::ostringstream oss;
  for (int i = height - 1; i >= 0; i--) {
    oss << std::setw(spacing) << i;
    _graph.push_back(oss.str() + line); 
    oss.str("");
  }
  oss << std::setw(spacing) << "    " << 0;
  for (int i = 1; i < width; i++) {
    if (i > 9) {
      oss << " " << i;
    }
    else {
      oss << "  " << i;
    }
  }
  _graph.push_back(oss.str());
}

void Graph::print_graph() {
  std::vector<std::string>::iterator it = _graph.begin();
  std::vector<std::string>::iterator end = _graph.end();
  for (; it < end; it++) {
    std::cout << *it << std::endl;
  }
}

void Graph::add_point(float x, float y) {
  _points.push_back(Vector2(x, y));
}

void Graph::display_points() const {
  int width = _size.getX();
  int height = _size.getY();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // REMOVE??
    }
  }
}
