/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:09:21 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/11 15:54:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../include/Worker.hpp"

#define DEFAULT_USES 10
#define MAX_USES 100

class Shovel {
  private:
    int _numberOfUses;
    Worker *_worker;
  public:
    Shovel();
    Shovel(int uses);
    Shovel(const Shovel &copy);
    Shovel &operator=(const Shovel &copy);
    ~Shovel();
    void assign_worker(Worker *worker);
    void use();
};