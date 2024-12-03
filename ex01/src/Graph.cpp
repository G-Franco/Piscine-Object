/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:47:43 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/03 11:26:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

Graph::Graph()
  : _size(1, 1) {
    build_graph();
  }

Graph::Graph(float width, float height, std::vector<std::string> &args)
  : _size(width, height) {
    if (_size.getX() < 1 || _size.getY() < 1) {
      throw std::runtime_error("Graph size must be positive\n");
    }
    if (_size.getX() > MAX_SIZE || _size.getY() > MAX_SIZE) {
      std::ostringstream err;
      err << "Graph size cannot exceed " << MAX_SIZE << "\n";
      throw std::runtime_error(err.str());
    }
    build_graph();
    validate_input(args);
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

void Graph::validate_input(std::vector<std::string> &args) {
  if (args.empty()) {
    return;
  }
  std::string path;
  std::vector<Vector2> points_to_add;
  try {
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++) {
      path = FILE_DIR + *it;
      std::vector<Vector2> temp = read_points_from_file(path);
      if (!temp.empty()) {
        points_to_add.insert(points_to_add.end(), temp.begin(), temp.end());
      }
    }
    if (points_to_add.empty()) {
      throw std::runtime_error("No points to add from file(s), check formatting\n");
    }
    for (std::vector<Vector2>::iterator it = points_to_add.begin(); it != points_to_add.end(); it++) {
      add_point(it->getX(), it->getY());
    }
  }
  catch (const std::runtime_error &err) {
    throw std::runtime_error("Error in file: " + path + "\n\t" + err.what());
  }
  display_points();
  print_graph();
}

void Graph::build_graph() {
  int width = _size.getX();
  int height = _size.getY();
  std::string line;
  for (int i = 0; i < width; i++) {
    line += "  .";
  }
  std::ostringstream oss;
  for (int i = height - 1; i >= 0; i--) {
    oss << std::setw(SPACING) << i;
    _graph.push_back(oss.str() + line); 
    oss.str("");
  }
  oss << std::setw(SPACING) << "    " << 0;
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
  add_point(Vector2(x, y), false, _points);
}

void Graph::add_point(Vector2 point, bool from_file, std::vector<Vector2> &target) {
  if (point.getX() < 0 || point.getX() >= _size.getX() ||
      point.getY() < 0 || point.getY() >= _size.getY()) {
    throw std::runtime_error("Point coordinates out of bounds\n");
  }
  if (std::find(_points.begin(), _points.end(), point) != _points.end()) {
    throw std::runtime_error("Error: Point already exists\n");
  }
  target.push_back(point);
  if (from_file) {
    return;
  }
  int row = _size.getY() - point.get_nearest_Y() - 1;
  int col = SPACING + 2 + (point.get_nearest_X() * 3);
  _graph[row][col] = 'x';
}

void Graph::display_points() const {
  if (_points.empty()) {
    std::cout << "No points to display\n";
    return;
  }
  std::vector<Vector2>::const_iterator it = _points.begin();
  std::vector<Vector2>::const_iterator end = _points.end();
  for (; it < end; it++) {
    std::cout << "Point: (" << it->getX() << ", " << it->getY() << ")\n";
  }
}

std::vector<Graph::Vector2> Graph::read_points_from_file(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (!file) {
      throw std::runtime_error("Can't open file\n");
  }
  if (file.peek() == std::ifstream::traits_type::eof()) {
      throw std::runtime_error("File is empty\n");
  }
  std::vector<Vector2> file_points;
  std::string line;
  std::ostringstream error;
  size_t line_number = 0;
  while (std::getline(file, line)) {
      line_number++;
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
      if (line.empty()) continue;
      size_t comma = line.find(',');
      if (comma == std::string::npos || comma == 0 || comma == line.length() - 1) {
          error << "Invalid format at line " << line_number << "\n";
          throw std::runtime_error(error.str());
      }
      std::istringstream left(line.substr(0, comma));
      std::istringstream right(line.substr(comma + 1));
      float x, y;
      if (!(left >> x) || !(right >> y)) {
          error << "Invalid number format at line " << line_number << "\n";
          throw std::runtime_error(error.str());
      }
      std::string leftovers;
      if (left >> leftovers || right >> leftovers) {
          error << "Invalid number format at line " << line_number << "\n";
          throw std::runtime_error(error.str());
      }
      try {
        add_point(Vector2(x, y), true, file_points);
      }
      catch(const std::exception& e) {
        std::ostringstream err;
        err << "Error in file: " << filename << " at line " << line_number << "\n\t"
        << e.what() << "\n";
        std::cerr << err.str();
      }
  }
  return file_points;
}
