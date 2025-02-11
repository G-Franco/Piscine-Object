/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:04:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HeadmasterOffice.hpp"

HeadmasterOffice::HeadmasterOffice()
  : Room() {}

HeadmasterOffice::HeadmasterOffice(const HeadmasterOffice &copy)
  : Room(copy) {}
  
HeadmasterOffice &HeadmasterOffice::operator=(const HeadmasterOffice &copy) {
  (void)copy;
  return *this;
}

HeadmasterOffice::~HeadmasterOffice() {}
