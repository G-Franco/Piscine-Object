/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:20:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/03 11:29:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

std::vector<std::string> av_to_vector(int ac, char **av) {
  std::vector<std::string> args;
  for (int i = 1; i < ac; i++) {
    args.push_back(av[i]);
  }
  return args;
}

void test_graph(float width, float height, std::vector<std::string> args, std::vector<std::pair<float, float> > points) {
  try {
    Graph graph(width, height, args);
    for (std::vector<std::pair<float, float> >::iterator it = points.begin(); it != points.end(); it++) {
      graph.add_point(it->first, it->second);
    }
    graph.display_points();
    graph.print_graph();
  } catch (const std::exception &error) {
    std::cerr << error.what();
  }
}

int main(int ac, char **av) {
  std::vector<std::string> error_files;
  error_files.push_back("test_empty");
  error_files.push_back("test_errors_1");
  error_files.push_back("test_errors_2");
  error_files.push_back("test_errors_3");
  error_files.push_back("test_errors_4");
  error_files.push_back("test_errors_5");
  error_files.push_back("test_errors_6");
  error_files.push_back("test_errors_7");

  std::vector<std::string> args = av_to_vector(ac, av);
  std::vector<std::pair<float, float> > test_points;

  std::cout << "Testing error cases:\n";
  std::cout << "\nTesting wrong dimensions:\n";
  test_graph(0, 1, args, test_points);
  std::cout << "-------------\n";
  test_graph(1, 0, args, test_points);
  std::cout << "-------------\n";
  test_graph(-1, 1, args, test_points);
  std::cout << "-------------\n";
  test_graph(1, -1, args, test_points);
  std::cout << "-------------\n";
  test_graph(MAX_SIZE, 1, args, test_points);
  std::cout << "-------------\n";
  test_graph(1, MAX_SIZE, args, test_points);
  std::cout << "-------------\n";
  test_graph(MAX_SIZE + 1, 1, args, test_points);
  std::cout << "-------------\n";
  test_graph(1, MAX_SIZE + 1, args, test_points);
  std::cout << "-------------\n";
  test_graph(std::numeric_limits<float>::max(), 1, args, test_points);
  std::cout << "-------------\n";
  test_graph(1, std::numeric_limits<float>::max(), args, test_points);
  std::cout << "-------------\n";

  std::cout << "\nTesting error cases in files:\n";
  for (size_t i = 0; i < error_files.size(); i++) {
    args.clear();
    args.push_back(error_files[i]);
    std::cout << "Testing file: " << error_files[i] << "\n";
    test_graph(10, 10, args, test_points);
    std::cout << "-------------\n";
  }

  std::cout << "\nTesting ok files:\n";
  args.clear();
  args.push_back("test_ok");
  test_graph(10, 10, args, test_points);
  std::cout << "-------------\n";
  args.clear();
  args.push_back("test_ok2");
  test_graph(10, 10, args, test_points);
  std::cout << "-------------\n";

  std::cout << "\nTesting with 2 ok files:\n";
  args.push_back("test_ok");
  test_graph(10, 10, args, test_points);
  args.clear();
  std::cout << "-------------\n";

  std::cout << "\nTesting adding points manually with no files:\n";
  std::cout << "\nTesting error cases:\n";
  test_points.push_back(std::make_pair(-1, 0));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  test_points.push_back(std::make_pair(0, -1));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  test_points.push_back(std::make_pair(10, 0));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  test_points.push_back(std::make_pair(0, 10));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  test_points.push_back(std::make_pair(1, 1));
  test_points.push_back(std::make_pair(1, 1));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  std::cout << "-------------\n";
  std::cout << "\nTesting limit cases:\n";
  test_points.push_back(std::make_pair(std::numeric_limits<float>::max(), 0));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  test_points.push_back(std::make_pair(0, std::numeric_limits<float>::max()));
  test_graph(10, 10, args, test_points);
  test_points.clear();
  std::cout << "-------------\n";
  std::cout << "\nTesting ok cases:\n";
  test_points.push_back(std::make_pair(0, 0));
  test_points.push_back(std::make_pair(1, 1));
  test_points.push_back(std::make_pair(2, 2));
  test_points.push_back(std::make_pair(3, 3));
  test_points.push_back(std::make_pair(1, 8));
  test_points.push_back(std::make_pair(8, 1));
  test_points.push_back(std::make_pair(8, 8));
  test_points.push_back(std::make_pair(5.4, 5.5));
  test_points.push_back(std::make_pair(8.9, 4));
  test_graph(10, 10, args, test_points);
  std::cout << "-------------\n";
  return 0;  
}
