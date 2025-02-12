/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:30:49 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 14:32:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Secretary.hpp"

Secretary::Secretary(std::string p_name)
  : Staff(p_name) {}

Secretary::Secretary(const Secretary &copy)
  : Staff(copy) {}

Secretary &Secretary::operator=(const Secretary &copy) {
  (void)copy;
  return *this;
}

Secretary::~Secretary() {}

Form* Secretary::createForm(FormType p_formType) {
  // TODO: Implement when there is info
  (void)p_formType;
  return NULL;
}

void Secretary::archiveForm() {
  // TODO: Implement when there is info
}
