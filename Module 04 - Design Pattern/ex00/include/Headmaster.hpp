/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:38:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"

class Headmaster : public Staff {
  private:
  	std::vector<Form*> _formToValidate;
  
  public:
  	void receiveForm(Form* p_form);
};
