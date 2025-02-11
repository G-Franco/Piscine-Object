/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:17 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:18:03 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Form.hpp"

class Staff : public Person {
  private:
    Staff();

  public:
    Staff(std::string p_name);
    Staff(const Staff &copy);
    Staff &operator=(const Staff &copy);
    ~Staff();
  	void sign(Form* p_form);
};
