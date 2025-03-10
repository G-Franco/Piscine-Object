/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Train.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:33:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/10 14:23:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Time.hpp"

class Train {
  private:
    std::string _name;
    double _weight;
    double _friction_coefficient;
    double _max_acceleration_force;
    double _max_break_force;
    std::string _departure_station;
    std::string _arrival_station;
    Time _departure_time;
    Time _stop_duration;

    static constexpr double MIN_WEIGHT = 5.0;
    static constexpr double MAX_WEIGHT = 1000.0;
    static constexpr double MIN_FRICTION_COEFF = 0.01;
    static constexpr double MAX_FRICTION_COEFF = 0.5;

  public:
    Train() = delete;
    Train(const std::string &name, double weight, double friction_coefficient,
          double max_acceleration_force, double max_break_force,
          const std::string &departure_station, const std::string &arrival_station,
          const Time &departure_time, const Time &stop_duration);
    Train(const Train &copy);
    Train &operator=(const Train &copy);
    bool operator==(const Train &other) const;
    ~Train();
    void validate_values();
    std::string get_name() const;
};
