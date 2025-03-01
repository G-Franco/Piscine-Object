/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaffRestRoom.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:08 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 15:10:20 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class StaffRestRoom : public Room {
  private:
  
  public:
    StaffRestRoom();
    StaffRestRoom(const StaffRestRoom &copy);
    StaffRestRoom &operator=(const StaffRestRoom &copy);
    bool operator==(const StaffRestRoom &other) const;
    ~StaffRestRoom();
};
