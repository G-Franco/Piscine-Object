/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Central.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:43:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/15 15:14:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Central.hpp"
#include "../include/Train.hpp"

Central::Central()
  : _network(_network),
    _trains(_trains) {}

Central::~Central() {}

void Central::calculate_paths() {
  for (auto &train : _trains) {
    train_path(train);
  }
}

void Central::train_path(Train &train) {
  
}

int Central::calculate_time_on_path(const Path &path, const Train &train) {
  
}
