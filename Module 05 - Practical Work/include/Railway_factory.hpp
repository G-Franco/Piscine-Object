/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Railway_factory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:16:04 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 17:17:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

struct Rail;
class Train;

// For factory pattern
class Railway_factory {
  private:
    // TODO: Check if these should stay here or go global
    static constexpr double MIN_RAIL_LENGTH = 5.0;
    static constexpr double MIN_SPEED_LIMIT = 100.0;
  public:
    Railway_factory() = default;
    Railway_factory(const Railway_factory &copy) = delete;
    Railway_factory &operator=(const Railway_factory &copy) = delete;
    ~Railway_factory() = default;
    void create_node(const std::string &node_name,
                     std::vector<std::string> &nodes);
    void create_rail(const std::string &node1,
                     const std::string &node2,
                     double length, 
                     double speed_limit,
                     std::vector<std::string> &nodes,
                     std::vector<Rail> &rails);
    void create_train(const std::string &name,
                      double weight,
                      double friction_coefficient,
                      double max_acceleration_force,
                      double max_break_force,
                      const std::string &departure_station,
                      const std::string &arrival_station,
                      const std::string &departure_time,
                      const std::string &stop_duration,
                      std::vector<Train> &trains,
                      std::vector<std::string> &nodes);
};