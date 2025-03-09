/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AValidation.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:38:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 17:30:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Railway_factory.hpp"

class Rail;
class Train;

// For strategy pattern
class AValidation {
  protected:
    static Railway_factory _factory;
    std::vector<std::string> &_nodes;
    std::vector<Rail> &_rails;
    std::vector<Train> &_trains;
  
  public:
    AValidation(std::vector<std::string> &nodes,
                std::vector<Rail> &rails,
                std::vector<Train> &trains);
    AValidation(const AValidation &copy) = delete;
    AValidation &operator=(const AValidation &copy) = delete;
    virtual ~AValidation() = default;
    virtual bool validate(std::ifstream &file) = 0;
};
