/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timetable.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:36:07 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/27 15:01:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>

struct Section;
struct Time;

class Timetable {
  private:
    std::vector<Section> _route;
    bool _reversed;

  public:
    Timetable();
    Timetable(const Timetable &copy);
    Timetable &operator=(const Timetable &copy);
    ~Timetable();
    void add_section(const Section &section);
    void set_times(Time start, double wait_time);
    void reverse();
};
