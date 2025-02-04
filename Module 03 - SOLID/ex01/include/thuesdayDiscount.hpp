/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuesdayDiscount.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:12:22 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 11:56:46 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "command.hpp"

class ThuesdayDiscountCommand : public Command {
  private:
    ThuesdayDiscountCommand(const ThuesdayDiscountCommand &copy);
    ThuesdayDiscountCommand &operator=(const ThuesdayDiscountCommand &copy);
  public:
    ThuesdayDiscountCommand();
    ThuesdayDiscountCommand(std::string date, std::string client, std::vector<std::pair<std::string, float> > articles);
    ~ThuesdayDiscountCommand();
    float get_total_price() override;
};
