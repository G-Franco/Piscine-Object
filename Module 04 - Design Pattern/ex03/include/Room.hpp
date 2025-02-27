/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:27:14 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 11:55:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <memory>

class Person;

class Room {
  protected:
  	static long long _ID;
    long long _id;
    std::weak_ptr<Room> _self;
    std::vector<std::weak_ptr<Person> > _occupants;

  public:
  	Room();
    Room(const Room &copy);
    Room &operator=(const Room &copy);
    bool operator==(const Room &other) const;
    virtual ~Room();
    void set_self(std::weak_ptr<Room> self);
  	virtual bool canEnter(std::weak_ptr<Person> person);
  	bool enter(std::weak_ptr<Person> person);
  	void exit(std::weak_ptr<Person> person);
  	void printOccupant();
    long long get_id() const;
    bool is_empty() const;
};
