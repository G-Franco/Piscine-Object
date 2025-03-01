/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:52 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/28 16:51:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include "observer.hpp"

class Room;
class Headmaster;

class Person : public IObserver{
  protected:
  	std::string _name;
    std::weak_ptr<Person> _self;
    std::weak_ptr<Room> _currentRoom;
    Headmaster *_headmaster;

    Person();

  public:
  	Person(std::string p_name);
    Person(const Person &copy);
    Person &operator=(const Person &copy);
    virtual ~Person();
    std::weak_ptr<Room> &room();
    void set_self(std::weak_ptr<Person> self);
    void set_room(std::weak_ptr<Room> room);
    void set_headmaster(Headmaster *headmaster);
    std::string get_name() const;
    bool exit_room();
    virtual void on_ring(Event event) = 0;
};
