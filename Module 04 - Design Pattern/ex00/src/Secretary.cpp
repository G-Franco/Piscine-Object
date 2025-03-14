/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:30:49 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 14:28:25 by gacorrei         ###   ########.fr       */
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
  (void)p_formType;
  return NULL;
}

void Secretary::archiveForm() {
}
