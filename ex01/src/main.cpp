/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:20:53 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/14 11:45:59 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"

int main() {
  try {
    Graph graph(1, 1);
    graph.print_graph();
  } catch (std::exception &e) {
    std::cerr << e.what();
  }
}
