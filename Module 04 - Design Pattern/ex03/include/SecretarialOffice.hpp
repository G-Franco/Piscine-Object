/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:31:10 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/20 17:56:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class Form;

class SecretarialOffice: public Room {
  private:
  	std::vector<Form*> _archivedForms;
  
  public:
    SecretarialOffice();
    SecretarialOffice(const SecretarialOffice &copy);
    SecretarialOffice &operator=(const SecretarialOffice &copy);
    bool operator==(const SecretarialOffice &other) const;
    ~SecretarialOffice();
};
