/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:31:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:34:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Form.hpp"

class SecretarialOffice: public Room {
  private:
  	std::vector<Form*> _archivedForms;
  
  public:
  
};
