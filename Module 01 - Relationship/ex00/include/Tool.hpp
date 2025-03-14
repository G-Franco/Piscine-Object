/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:11:28 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 14:04:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include "Worker.hpp"

class Worker;

#define DEFAULT_USES 10
#define SHOVEL_MAX_USES 100
#define HAMMER_MAX_USES 150

class Tool {
  protected:
    int _numberOfUses;
    Worker *_worker;
  public:
    Tool();
    Tool(int uses);
    Tool(const Tool &copy);
    Tool &operator=(const Tool &copy);
    virtual ~Tool();
    int get_number_of_uses() const;
    Worker *get_worker() const;
    void assign_worker(Worker *worker);
    virtual void use() = 0;
    virtual std::string get_type() const = 0;
};
