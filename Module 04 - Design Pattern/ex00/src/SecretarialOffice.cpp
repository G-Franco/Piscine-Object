/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:02:31 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:03:41 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/SecretarialOffice.hpp"

SecretarialOffice::SecretarialOffice()
  : Room() {}

SecretarialOffice::SecretarialOffice(const SecretarialOffice &copy)
  : Room(copy),
    _archivedForms(copy._archivedForms) {}

SecretarialOffice &SecretarialOffice::operator=(const SecretarialOffice &copy) {
  _archivedForms = copy._archivedForms;
  return *this;
}

SecretarialOffice::~SecretarialOffice() {}
