/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_text_logger.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:20:45 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 12:17:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_text_logger.hpp"

header_text_logger::header_text_logger(ILogger &logger, const std::string &header)
  : _logger(logger),
    _header(header) {}

header_text_logger::header_text_logger(const header_text_logger &copy)
  : _logger(copy._logger),
    _header(copy._header) {}

header_text_logger &header_text_logger::operator=(const header_text_logger &copy) {
  _logger = copy._logger;
  _header = copy._header;
  return *this;
}

header_text_logger::~header_text_logger() {}

void header_text_logger::write(const std::string &message) {
  _logger.write(_header + message);
}
