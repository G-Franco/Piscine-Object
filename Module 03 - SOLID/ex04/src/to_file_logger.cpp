/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_file_logger.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:52:59 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/08 17:03:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/to_file_logger.hpp"

to_file_logger::to_file_logger() {}

to_file_logger::to_file_logger(const std::string &file_name)
  : ILogger(),
    _file(file_name.c_str()) {
  if (!_file.is_open()) {
    throw std::runtime_error("Could not open file");
  }
}

to_file_logger::to_file_logger(const to_file_logger &copy)
  : ILogger(copy) {
  *this = copy;
}

to_file_logger &to_file_logger::operator=(const to_file_logger &copy) {
  _file = copy._file;
  return *this;
}

to_file_logger::~to_file_logger() {
  // Closing the file is not strictly necessary here as std::ofstream
  // will close the file when it goes out of scope.
  // It is just here to emphasize that the file is being closed.
  _file.close();
}

void to_file_logger::write(const std::string &message) {
  _file << message << std::endl;
}
