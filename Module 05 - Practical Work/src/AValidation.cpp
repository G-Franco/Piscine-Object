/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AValidation.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:08:40 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 17:31:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AValidation.hpp"

Railway_factory AValidation::_factory;

AValidation::AValidation(std::vector<std::string> &nodes,
                         std::vector<Rail> &rails,
                         std::vector<Train> &trains)
  : _nodes(nodes),
    _rails(rails),
    _trains(trains) {}
