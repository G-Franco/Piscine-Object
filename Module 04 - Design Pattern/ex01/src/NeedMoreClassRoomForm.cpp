/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:09:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:10:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/NeedMoreClassRoomForm.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm()
  : Form(FormType::NeedMoreClassRoom) {}

NeedMoreClassRoomForm::NeedMoreClassRoomForm(const NeedMoreClassRoomForm &copy)
  : Form(copy) {}

NeedMoreClassRoomForm &NeedMoreClassRoomForm::operator=(const NeedMoreClassRoomForm &copy) {
  (void)copy;
  return *this;
}

NeedMoreClassRoomForm::~NeedMoreClassRoomForm() {}

void NeedMoreClassRoomForm::execute() {
  std::cout << "Need more class room form executed\n";
}
