/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:16 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:09:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedMoreClassRoomForm : public Form {
  private:
  
  public:
    NeedMoreClassRoomForm();
    NeedMoreClassRoomForm(const NeedMoreClassRoomForm &copy);
    NeedMoreClassRoomForm &operator=(const NeedMoreClassRoomForm &copy);
    ~NeedMoreClassRoomForm();
  	void execute();
};
