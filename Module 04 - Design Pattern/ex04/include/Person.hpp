/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:52 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/26 11:44:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>

class Room;
class Headmaster;

class Person {
  protected:
  	std::string _name;
  	std::weak_ptr<Room> _currentRoom;
    Headmaster *_headmaster;

    Person();

  public:
  	Person(std::string p_name);
    Person(const Person &copy);
    Person &operator=(const Person &copy);
    virtual ~Person();
    std::weak_ptr<Room> &room();
    void set_room(std::weak_ptr<Room> room);
    void set_headmaster(Headmaster *headmaster);
    std::string get_name() const;
};
