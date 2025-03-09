/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rail_validation.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:16:11 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/09 16:16:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AValidation.hpp"

class Rail_validation : public AValidation {
  public:
    Rail_validation(std::vector<std::string> &nodes,
                    std::vector<Rail> &rails,
                    std::vector<Train> &trains);
    Rail_validation(const Rail_validation &copy) = delete;
    Rail_validation &operator=(const Rail_validation &copy) = delete;
    ~Rail_validation() = default;
    bool validate(std::ifstream &file) override;
};
