/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:52 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:33:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Room.hpp"

class Person {
  private:
  	std::string _name;
  	Room* _currentRoom;
  public:
  	Person(std::string p_name);
  	Room* room() {return (_currentRoom);}
};
