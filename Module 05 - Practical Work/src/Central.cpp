/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Central.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:43:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/27 11:05:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Central.hpp"
#include "../include/Train.hpp"
#include "../include/helper.hpp"
#include <cmath>

Central::Central()
  : _network(_network),
    _trains(_trains),
    _mapper(_network, _trains) {}

Central::~Central() {}

void Central::calculate_paths() {
  for (auto &train : _trains) {
    train_path(train);
  }
}

void Central::train_path(Train &train) {
  
}
