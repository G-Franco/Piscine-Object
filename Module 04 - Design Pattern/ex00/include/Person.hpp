/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:52 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/14 16:19:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Room.hpp"

class Room;

class Person {
  protected:
  	std::string _name;
  	Room *_currentRoom;

    Person();

  public:
  	Person(std::string p_name);
    Person(const Person &copy);
    Person &operator=(const Person &copy);
    virtual ~Person();
    Room *room();
    std::string get_name() const;
};
