/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:22:11 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/01 11:42:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Engine {
  private:
    bool _engine_state;
    
    Engine(const Engine &copy);
    Engine &operator=(const Engine &copy);

  public:
    Engine();
    ~Engine();
    void start();
    void stop();
    bool get_engine_state() const;
};
