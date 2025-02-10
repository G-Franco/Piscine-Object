/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_date_logger.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:26:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 12:17:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_date_logger.hpp"

header_date_logger::header_date_logger(ILogger &logger)
  : _logger(logger) {}

header_date_logger::header_date_logger(const header_date_logger &copy)
  : _logger(copy._logger) {}

header_date_logger &header_date_logger::operator=(const header_date_logger &copy) {
  _logger = copy._logger;
  return *this;
}

header_date_logger::~header_date_logger() {}

void header_date_logger::write(const std::string &message) {
  time_t now = std::time(0);
  std:: string current_time = std::ctime(&now);
  if (current_time.empty()) {
    throw std::runtime_error("Could not get current time");
  }
  // ctime adds a newline at the end, need to remove it 
  current_time.erase(current_time.length() - 1);
  _logger.write("[" + current_time + "] " + message);
}
