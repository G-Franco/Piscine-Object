/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:27:14 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 16:22:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include "Person.hpp"

// TODO: ARE THESE NECESSARY?
class Person;

class Room {
  protected:
  	static long long _ID;
    long long _id;
    std::vector<Person *> _occupants;

  public:
  	Room();
    Room(const Room &copy);
    Room &operator=(const Room &copy);
    ~Room();
  	bool canEnter(Person*);
  	bool enter(Person*);
  	void exit(Person*);
  	void printOccupant();
    long long get_id() const;
};
