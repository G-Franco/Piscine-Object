/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:52 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 16:18:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>

class Room;
class Headmaster;

class Person : public std::enable_shared_from_this<Person> {
  protected:
  	std::string _name;
  	Room *_currentRoom;
    Headmaster *_headmaster;

    Person();

  public:
  	Person(std::string p_name);
    Person(const Person &copy);
    Person &operator=(const Person &copy);
    virtual ~Person();
    Room *room();
    void set_room(Room *p_room);
    void set_headmaster(Headmaster *headmaster);
    std::string get_name() const;
};
