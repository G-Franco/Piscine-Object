/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_validation.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:33 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 16:05:41 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AValidation.hpp"

class Node_validation : public AValidation {
  public:
    Node_validation(std::vector<std::string> &nodes,
                    std::vector<Rail> &rails,
                    std::vector<Train> &trains);
    Node_validation(const Node_validation &copy) = delete;
    Node_validation &operator=(const Node_validation &copy) = delete;
    ~Node_validation() = default;
    bool validate(std::ifstream &file) override;
};
