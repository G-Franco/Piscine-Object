/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:31:52 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/11 15:04:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class HeadmasterOffice : public Room {
  private:
  
  public:
    HeadmasterOffice();
    HeadmasterOffice(const HeadmasterOffice &copy);
    HeadmasterOffice &operator=(const HeadmasterOffice &copy);
    ~HeadmasterOffice();
};
