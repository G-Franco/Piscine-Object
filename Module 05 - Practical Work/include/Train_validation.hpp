/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Train_validation.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:56:44 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 16:56:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AValidation.hpp"

class Train_validation : public AValidation {
  public:
    Train_validation(std::vector<std::string> &nodes,
                     std::vector<Rail> &rails,
                     std::vector<Train> &trains);
    Train_validation(const Train_validation &copy) = delete;
    Train_validation &operator=(const Train_validation &copy) = delete;
    ~Train_validation() = default;
    bool validate(std::ifstream &file) override;
};