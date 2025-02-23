/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:27:14 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 11:59:36 by gacorrei         ###   ########.fr       */
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
    std::vector<std::shared_ptr<Person> > _occupants;

  public:
  	Room();
    Room(const Room &copy);
    Room &operator=(const Room &copy);
    bool operator==(const Room &other) const;
    virtual ~Room();
  	virtual bool canEnter(std::shared_ptr<Person> person);
  	bool enter(std::shared_ptr<Person> person);
  	void exit(std::shared_ptr<Person> person);
  	void printOccupant();
    long long get_id() const;
    bool is_empty() const;
};
