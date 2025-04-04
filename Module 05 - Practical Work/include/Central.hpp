/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Central.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:36:58 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/04 14:53:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>
#include "Mapper.hpp"

struct Rail;
struct Path;
class Train;

class Central {
  private:
    std::unordered_map<std::string, std::vector<Rail *>> &_network;
    std::vector<Train> &_trains;
    Mapper _mapper;

  public:
    Central() = delete;
    Central(std::unordered_map<std::string, std::vector<Rail *>> &network,
            std::vector<Train> &trains);
    Central(const Central &copy) = delete;
    Central &operator=(const Central &copy) = delete;
    ~Central();
};
