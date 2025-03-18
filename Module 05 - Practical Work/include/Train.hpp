/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Train.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:33:18 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/18 14:55:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Time.hpp"

class Train {
  private:
    static int _id_counter;
    int _id;
    std::string _name;
    double _weight; // Kg
    double _friction_coefficient;
    double _max_acceleration_force; // N
    double _max_break_force; // N
    std::string _departure_station;
    std::string _arrival_station;
    Time _departure_time;
    Time _stop_duration;
    
    double _friction_force; // N
    double _aerodynamic_coefficient; //Dimensionless
    double _acceleration; // m/s^2
    double _deceleration; // m/s^2
    double _max_speed; // m/s
    double _time_to_max_speed; // s
    double _distance_to_max_speed; // m
    // These 2 assume train is at max speed
    double _time_to_stop; // s
    double _distance_to_stop; // m
    // Necessary distance to get to max speed and brake to a stop
    double _acceleration_deceleration_distance; // m
    double _current_speed; // m/s

    static constexpr double MIN_WEIGHT = 5.0;
    static constexpr double MAX_WEIGHT = 1000.0;
    static constexpr double MIN_FRICTION_COEFF = 0.01;
    static constexpr double MAX_FRICTION_COEFF = 0.5;
    static constexpr int MAX_STOP_DURATION = 15;
    // https://en.wikipedia.org/wiki/Density_of_air
    static constexpr double AIR_DENSITY = 1.225;
    // https://www.engineeringtoolbox.com/drag-coefficient-d_627.html
    static constexpr double DRAG_COEFFICIENT = 1.8;
    // https://www.thefreelibrary.com/Numerical+Analysis+of+the+Effect+of+Different+Nose+Shapes+on+Train...-a0814092594
    static constexpr double FRONTAL_AREA = 10.0;
    static constexpr double GRAVITY = 9.81;
    // Meters per second / Kilometers per hour conversion factor (both ways)
    static constexpr double MPS_KMH = 3.6;

    friend class Central;

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
    double friction_force(double friction_coefficient, double weight);
    double aerodynamic_coefficient(double air_density, double drag_coefficient, double frontal_area);
    double acceleration(double acceleration_force, double friction_force, double weight);
    double deceleration(double deceleration_force, double friction_force, double weight);
    double time_to_change_speed(double initial_speed, double target_speed, double acceleration);
    double distance_to_speed(double acceleration, double time_to_speed);
    double distance_to_stop(double speed, double deceleration);
    double acceleration_deceleration_distance(double distance_to_speed, double distance_to_stop);
    double max_speed(double net_acceleration_force, double aerodynamic_coefficient);
    std::string get_name() const;
};
