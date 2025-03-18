/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Train.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:33:13 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/18 10:30:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <cmath>
#include "../include/Train.hpp"

int Train::_id_counter = 0;

Train::Train(const std::string &name,
             double weight,
             double friction_coefficient,
             double max_acceleration_force,
             double max_break_force,
             const std::string &departure_station,
             const std::string &arrival_station,
             const Time &departure_time,
             const Time &stop_duration)
  : _id(++_id_counter),
    _name(name),
    _weight(weight),
    _friction_coefficient(friction_coefficient),
    _max_acceleration_force(max_acceleration_force),
    _max_break_force(max_break_force),
    _departure_station(departure_station),
    _arrival_station(arrival_station),
    _departure_time(departure_time),
    _stop_duration(stop_duration),
    _friction_force(friction_force(friction_coefficient, weight)),
    _aerodynamic_coefficient(aerodynamic_coefficient(AIR_DENSITY, DRAG_COEFFICIENT, FRONTAL_AREA)),
    _acceleration(acceleration(max_acceleration_force, _friction_force, weight)),
    _deceleration(deceleration(max_break_force, _friction_force, weight)),
    _max_speed(max_speed(max_acceleration_force - _friction_force, _aerodynamic_coefficient)),
    _time_to_max_speed(time_to_speed(_max_speed, _acceleration)),
    _distance_to_max_speed(distance_to_speed(_acceleration, _time_to_max_speed)),
    _distance_to_stop(distance_to_stop(_max_speed, _deceleration)),
    _acceleration_deceleration_distance(acceleration_deceleration_distance(_distance_to_max_speed, _distance_to_stop)),
    _current_speed(0) {
  validate_values();
}

Train::Train(const Train &copy)
  : _id(++_id_counter),
    _name(copy._name),
    _weight(copy._weight),
    _friction_coefficient(copy._friction_coefficient),
    _max_acceleration_force(copy._max_acceleration_force),
    _max_break_force(copy._max_break_force),
    _departure_station(copy._departure_station),
    _arrival_station(copy._arrival_station),
    _departure_time(copy._departure_time),
    _stop_duration(copy._stop_duration),
    _friction_force(copy._friction_force),
    _aerodynamic_coefficient(copy._aerodynamic_coefficient),
    _acceleration(copy._acceleration),
    _deceleration(copy._deceleration),
    _time_to_max_speed(copy._time_to_max_speed),
    _distance_to_max_speed(copy._distance_to_max_speed),
    _distance_to_stop(copy._distance_to_stop),
    _acceleration_deceleration_distance(copy._acceleration_deceleration_distance),
    _max_speed(copy._max_speed),
    _current_speed(0) {
}

Train &Train::operator=(const Train &copy) {
  if (this == &copy) {
    return *this;
  }
  _name = copy._name;
  _weight = copy._weight;
  _friction_coefficient = copy._friction_coefficient;
  _max_acceleration_force = copy._max_acceleration_force;
  _max_break_force = copy._max_break_force;
  _departure_station = copy._departure_station;
  _arrival_station = copy._arrival_station;
  _departure_time = copy._departure_time;
  _stop_duration = copy._stop_duration;
  _friction_force = copy._friction_force;
  _aerodynamic_coefficient = copy._aerodynamic_coefficient;
  _acceleration = copy._acceleration;
  _deceleration = copy._deceleration;
  _max_speed = copy._max_speed;
  _time_to_max_speed = copy._time_to_max_speed;
  _distance_to_max_speed = copy._distance_to_max_speed;
  _distance_to_stop = copy._distance_to_stop;
  _acceleration_deceleration_distance = copy._acceleration_deceleration_distance;
  _current_speed = 0;
  return *this;
}

bool Train::operator==(const Train &other) const {
  return _name == other._name;
}

Train::~Train() {}

void Train::validate_values() {
  std::stringstream error;
  error << "Error: invalid train parameters\n"
        << "Weight [" << MIN_WEIGHT << "-" << MAX_WEIGHT << "]\n"
        << "Friction coefficient ["
        << MIN_FRICTION_COEFF << "-" << MAX_FRICTION_COEFF << "]\n"
        << "Forces must be positive\n"
        << "Time format: HHhMM\n"
        << "Stop duration must not exceed " << MAX_STOP_DURATION << " minutes";
  if (_weight < MIN_WEIGHT ||
      _weight > MAX_WEIGHT ||
      _friction_coefficient < MIN_FRICTION_COEFF ||
      _friction_coefficient > MAX_FRICTION_COEFF ||
      _max_acceleration_force <= 0 ||
      _max_break_force <= 0 ||
      _departure_time._hours == -1 ||
      _stop_duration._hours == -1 ||
      _stop_duration._hours != 0 ||
      _stop_duration._minutes > MAX_STOP_DURATION) {
    throw std::runtime_error(error.str());
  }
  if (_max_acceleration_force <= _friction_force) {
    throw std::runtime_error("Train won't move, acceleration force too low");
  }
}

std::string Train::get_name() const {
  return _name;
}

double Train::friction_force(double friction_coefficient, double weight) {
  // Friction force f = μN
  return friction_coefficient * weight * GRAVITY;
}

double Train::aerodynamic_coefficient(double air_density, double drag_coefficient, double frontal_area) {
  return 0.5 * air_density * drag_coefficient * frontal_area;
}

double Train::acceleration(double acceleration_force, double friction_force, double weight) {
  // Acceleration = forces / mass
  return (acceleration_force - friction_force) / weight;
}

// Necessary since i'm assuming forces are all positive
double Train::deceleration(double deceleration_force, double friction_force, double weight) {
  // Deceleration = forces / mass
  return (deceleration_force + friction_force) / weight;
}

double Train::time_to_speed(double speed, double acceleration) {
  // Base formula: acceleration = speed / time
  // Time = speed / acceleration
  return speed / acceleration;
}

double Train::distance_to_speed(double acceleration, double time_to_speed) {
  // Base formula: Distance = initial_speed * time + acceleration * time^2 / 2
  // Distance = acceleration * time^2 / 2
  return acceleration * std::pow(time_to_speed, 2) / 2;
}

double Train::distance_to_stop(double speed, double deceleration) {
  // Distance = speed^2 / (2 * deceleration)
  return std::pow(speed, 2) / (2 * deceleration);
}

double Train::acceleration_deceleration_distance(double distance_to_speed, double distance_to_stop) {
  // Total distance required to reach max speed and brake to a stop,
  // starting from a standstill
  return distance_to_speed + distance_to_stop;
}

// Net acceleration force = max acceleration force - friction force
double Train::max_speed(double net_acceleration_force, double aerodynamic_coefficient) {
  // Unlike in school, air resistance is considered, but in a simplified way.
  // Since air resistance increases with speed, 
  // the max speed is reached when air resistance equals available force

  // Drive force = friction force + air resistance
  // Air resistance = aerodynamic coefficient * speed^2
  // Drive force = friction force + (aerodynamic coefficient * speed^2)
  // speed^2 = (drive force - friction force) / aerodynamic coefficient
  // speed = sqrt((drive force - friction force) / aerodynamic coefficient)
  return std::sqrt(net_acceleration_force / aerodynamic_coefficient);
}
