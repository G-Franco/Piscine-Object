/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:31:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:03:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Form.hpp"

class SecretarialOffice: public Room {
  private:
  	std::vector<Form*> _archivedForms;
  
  public:
    SecretarialOffice();
    SecretarialOffice(const SecretarialOffice &copy);
    SecretarialOffice &operator=(const SecretarialOffice &copy);
    ~SecretarialOffice();
};
