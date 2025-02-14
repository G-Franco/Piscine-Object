/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:17 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 16:19:11 by gacorrei         ###   ########.fr       */
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
    bool operator==(const Staff &other) const;
    virtual ~Staff();
  	void sign(Form* p_form);
};
