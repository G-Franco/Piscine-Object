/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_text_logger.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:16:01 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 12:15:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILogger.hpp"

class header_text_logger : public ILogger {
  private:
    ILogger &_logger;
    std::string _header;

    header_text_logger();
    header_text_logger(const header_text_logger &copy);
    header_text_logger &operator=(const header_text_logger &copy);
    
  public:
    header_text_logger(ILogger &logger, const std::string &header);
    ~header_text_logger();
    void write(const std::string &message);
};
