/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:34:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HeadmasterOffice.hpp"

HeadmasterOffice::HeadmasterOffice()
  : Room() {}

HeadmasterOffice::HeadmasterOffice(const HeadmasterOffice &copy)
  : Room(copy) {}
  
HeadmasterOffice &HeadmasterOffice::operator=(const HeadmasterOffice &copy) {
  _id = copy._id;
  return *this;
}

bool HeadmasterOffice::operator==(const HeadmasterOffice &other) const {
  return _id == other._id;
}

HeadmasterOffice::~HeadmasterOffice() {}
