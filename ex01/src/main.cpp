/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:20:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/25 15:55:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

// TODO - rewrite main with new file reading in mind

int main(int ac, char **av) {
  try {
    Graph graph(5, 11, ac, av);
  }
  catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }

  try {
    // Test with files in the files folder as input args
    // TODO - Check points added to the wrong place in test ok file
    Graph graph(10, 10, ac, av);
  }
  catch(const std::exception& e) {
    // std::cerr << e.what() << '\n';
  }

  try {
    ac = 1;
    Graph graph(10, 10, ac, av);
    graph.print_graph();
    graph.add_point(0, 0);
    graph.display_points();
    graph.print_graph();
    graph.add_point(5, 5);
    graph.display_points();
    graph.print_graph();
    graph.add_point(4, 3);
    graph.display_points();
    graph.print_graph();
    graph.add_point(1.2, 3.9);
    graph.display_points();
    graph.print_graph();
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }
}
