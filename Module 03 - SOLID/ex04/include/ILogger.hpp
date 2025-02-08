/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILogger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:58:55 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/08 16:02:41 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ILogger {
  public:
    virtual ~ILogger() {}
    virtual void write(const std::string &message) = 0;
};
