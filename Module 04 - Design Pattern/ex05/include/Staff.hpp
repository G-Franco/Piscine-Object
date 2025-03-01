/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:17 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/28 16:43:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include "Person.hpp"

class Form;

class Staff : public Person {
  private:
    Staff();

  public:
    Staff(std::string p_name);
    Staff(const Staff &copy);
    Staff &operator=(const Staff &copy);
    bool operator==(const Staff &other) const;
    virtual ~Staff();
  	virtual void sign(std::shared_ptr<Form> p_form);
    virtual void on_ring(Event event) override;
};
