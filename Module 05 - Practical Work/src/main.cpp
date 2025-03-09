/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:46:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 19:11:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File_checker.hpp"

// TODO: Add colors
void help() {
  std::cout << "Usage: ./trains [file1] [file2]\n"
            << "\nFile1 should contain nodes and rails (nodes before rails, no empty lines)\n"
            << "-Node line formatting:\nNode [node_name]\n"
            << "-Rail line formatting:\nRail [node1] [node2] [length] [speed_limit]\n"
            << "\nFile2 should contain trains\n"
            << "-Train line formatting:\nTrain[name] [weight] "
            << "[friction_coefficient] [max_acceleration_force] "
            << "[max_break_force] [departure_station] [arrival_station] "
            << "[departure_time] [stop_duration]\n"
            << "\nNumerical values are expected to be doubles\n";
}

int main(int ac, char**av) {
  if (ac < 2 || ac > 3) {
    std::cout << "Usage: ./trains [file1] [file2]\n"
              << "Use --help or -h for more information\n";
    return 1;
  }
  if (std::string(av[1]) == "--help" || std::string(av[1]) == "-h") {
    help();
    return 0;
  }
  return 0;
}
