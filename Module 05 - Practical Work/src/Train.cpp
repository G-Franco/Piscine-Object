/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Train.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:33:13 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/14 10:02:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
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
    _stop_duration(stop_duration) {
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
    _stop_duration(copy._stop_duration) {
  validate_values();      
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
  return *this;
}

bool Train::operator==(const Train &other) const {
  return _name == other._name;
}

Train::~Train() {}

// TODO: ADD VALIDATION FOR STOP DURATION, IT SHOULD ONLY BE A FEW MINUTES
void Train::validate_values() {
  std::stringstream error;
  error << "Error: invalid train parameters\n"
        << "Weight [" << MIN_WEIGHT << "-" << MAX_WEIGHT << "]\n"
        << "Friction coefficient [" << MIN_FRICTION_COEFF << "-" << MAX_FRICTION_COEFF << "]\n"
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
}

std::string Train::get_name() const {
  return _name;
}
