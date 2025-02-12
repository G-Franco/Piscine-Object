/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:38:38 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:31:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"

class Secretary : public Staff {
  private:
    Secretary();
  
  public:
    Secretary(std::string p_name);
    Secretary(const Secretary &copy);
    Secretary &operator=(const Secretary &copy);
    ~Secretary();
  	Form* createForm(FormType p_formType);
  	void archiveForm();
};
