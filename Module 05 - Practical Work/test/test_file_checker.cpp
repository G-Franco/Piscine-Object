/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_checker.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:33:12 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/08 13:00:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File_checker.hpp"

int main(int ac, char **av) {
  if (ac != 3) {
    std::cout << "Usage: ./test_file_checker node_file rail_file\n";
    return 1;
  }
  File_checker fc(av[1], av[2]);
  return fc.validate_files();
}
