/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:46:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/10 14:23:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File_checker.hpp"
#include "../include/text.hpp"

void help() {
  std::cout << BOLD << "Usage: ./trains [file1] [file2]" << RESET << "\n"
            << BLUE << "\nFile1 should contain nodes and rails (nodes before rails, no empty lines)" << RESET << "\n"
            << GREEN << "Node [node_name]" << RESET << "\n"
            << GREEN << "Rail [node1] [node2] [length] [speed_limit]" << RESET << "\n"
            << BLUE << "\nFile2 should contain trains (no empty lines)" << RESET << "\n"
            << GREEN << "Train[name] [weight] "
            << "[friction_coefficient] [max_acceleration_force] "
            << "[max_break_force] [departure_station] [arrival_station] "
            << "[departure_time] [stop_duration]" << RESET << "\n"
            << BOLD << "\nNumerical values are expected to be doubles\n";
}

int main(int ac, char**av) {
  if (ac != 3) {
    if (ac > 1 &&
       (std::string(av[1]) == "--help" ||
        std::string(av[1]) == "-h")) {
      help();
      return 0;
    }
    std::cout << "Usage: ./trains [file1] [file2]\n"
              << "Use --help or -h for more information\n";
    return 1;
  }
  File_checker fc(av[1], av[2]);
  if (!fc.validate_files()) {
    return 1;
  }
  fc.test_print();
  return 0;
}
