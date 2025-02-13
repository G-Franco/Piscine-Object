/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Courtyard.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:25 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:07:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class Courtyard : public Room {
  private:
  
  public:
    Courtyard();
    Courtyard(const Courtyard &copy);
    Courtyard &operator=(const Courtyard &copy);
    bool operator==(const Courtyard &other) const;
    ~Courtyard();
};
