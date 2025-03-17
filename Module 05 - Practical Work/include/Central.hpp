/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Central.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:36:58 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/15 15:14:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>

struct Rail;
struct Path;
class Train;

class Central {
  private:
    std::unordered_map<std::string, std::vector<Rail *>> &_network;
    std::vector<Train> &_trains;

  public:
    Central();
    Central(const Central &copy) = delete;
    Central &operator=(const Central &copy) = delete;
    ~Central();
    void calculate_paths();
    void train_path(Train &train);
    int calculate_time_on_path(const Path &path, const Train &train);
};
