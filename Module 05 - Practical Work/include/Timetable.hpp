/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timetable.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:36:07 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/15 11:20:56 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>

struct Section;

class Timetable {
  private:
    std::vector<Section> _route;
    int _stop_duration;

  public:
    Timetable() = delete;
    Timetable(int stop_duration);
    Timetable(const Timetable &copy) = delete;
    Timetable &operator=(const Timetable &copy) = delete;
    ~Timetable();
};
