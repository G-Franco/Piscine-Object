/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:00:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/01 11:01:48 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Event.hpp"

class IObserver;

class Bell {
  private:
    std::vector<std::weak_ptr<IObserver>> _observers;
  
  public:
    Bell();
    ~Bell();
    void ring(Event event);
    void add_observer(std::weak_ptr<IObserver> &observer);
    void remove_observer(std::weak_ptr<IObserver> &observer);
};
