/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:20:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/23 11:29:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

// TODO - rewrite main with new file reading in mind

int main(int ac, char **av) {
  
  try {
    Graph graph(6, 6);
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
    std::cerr << e.what();
  }
}
