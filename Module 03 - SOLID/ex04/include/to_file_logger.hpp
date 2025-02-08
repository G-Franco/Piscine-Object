/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_file_logger.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:40:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/08 16:56:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILogger.hpp"
#include <fstream>

class to_file_logger : public ILogger {
  private:
    std::ofstream _file;

    to_file_logger();
    to_file_logger(const to_file_logger &copy);
    to_file_logger &operator=(const to_file_logger &copy);

  public:
    to_file_logger(const std::string &file_name);
    ~to_file_logger() {}
    void write(const std::string &message);
};
