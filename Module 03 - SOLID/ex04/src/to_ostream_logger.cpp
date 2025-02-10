/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ostream_logger.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:06:27 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 12:17:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/to_ostream_logger.hpp"

to_ostream_logger::to_ostream_logger()
  : ILogger(),
    _ostream(std::cout) {}

to_ostream_logger::to_ostream_logger(std::ostream &os)
  : ILogger(),
    _ostream(os) {}

to_ostream_logger::~to_ostream_logger() {}

void to_ostream_logger::write(const std::string &message) {
  _ostream << message << std::endl;
}
