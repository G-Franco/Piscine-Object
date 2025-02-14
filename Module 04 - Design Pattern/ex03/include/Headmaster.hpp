/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/13 15:55:39 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Secretary.hpp"

class Headmaster : public Staff {
  private:
  	std::vector<std::shared_ptr<Form> > _formToValidate;

    Headmaster();

  public:
    Headmaster(std::string p_name);
    Headmaster(const Headmaster &copy);
    Headmaster &operator=(const Headmaster &copy);
    ~Headmaster();
  	void receiveForm(std::shared_ptr<Form> p_form);
    void sign_form(std::shared_ptr<Form> form);
    void execute_form(std::shared_ptr<Form> form);
    void sign_all_forms();
    void execute_all_forms();
    void clean_forms(Secretary &secretary);
};
