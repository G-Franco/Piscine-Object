/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Central.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:43:37 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/04 14:53:46 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Central.hpp"
#include "../include/Train.hpp"
#include "../include/helper.hpp"
#include <cmath>

Central::Central(std::unordered_map<std::string, std::vector<Rail *>> &network,
                 std::vector<Train> &trains)
  : _network(network),
    _trains(trains),
    _mapper(_network, _trains) {
}

Central::~Central() {}
