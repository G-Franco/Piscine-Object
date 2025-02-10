/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_date_logger.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:26:32 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 12:15:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILogger.hpp"
#include <ctime>

class header_date_logger : public ILogger {
  private:
    ILogger &_logger;

    header_date_logger();
    header_date_logger(const header_date_logger &copy);
    header_date_logger &operator=(const header_date_logger &copy);
    
  public:
    header_date_logger(ILogger &logger);
    ~header_date_logger();
    void write(const std::string &message);
};
