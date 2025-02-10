/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:27:14 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:30:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "Person.hpp"

// TODO: ARE THESE NECESSARY?
class Person;

class Room {
  private:
  	long long ID;
  	std::vector<Person*> _occupants;

  public:
  	Room();
  	bool canEnter(Person*);
  	void enter(Person*);
  	void exit(Person*);
  	void printOccupant();
};
