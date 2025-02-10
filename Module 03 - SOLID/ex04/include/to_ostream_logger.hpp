/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ostream_logger.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:05:45 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 12:13:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILogger.hpp"

class to_ostream_logger : public ILogger {
  private:
    std::ostream &_ostream;

    to_ostream_logger();
    to_ostream_logger(const to_ostream_logger &copy);
    to_ostream_logger &operator=(const to_ostream_logger &copy);

  public:
    to_ostream_logger(std::ostream &os);
    ~to_ostream_logger();
    void write(const std::string &message);
};
