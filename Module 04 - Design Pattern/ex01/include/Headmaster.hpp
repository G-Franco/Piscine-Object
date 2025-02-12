/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:29:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"

class Headmaster : public Staff {
  private:
  	std::vector<Form*> _formToValidate;

    Headmaster();

  public:
    Headmaster(std::string p_name);
    Headmaster(const Headmaster &copy);
    Headmaster &operator=(const Headmaster &copy);
    ~Headmaster();
  	void receiveForm(Form* p_form);
};
