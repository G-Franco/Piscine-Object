/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packageReductionDiscount.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:59:25 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 15:37:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "command.hpp"

class PackageReductionDiscountCommand : public Command {
  private:
    PackageReductionDiscountCommand(const PackageReductionDiscountCommand &copy);
    PackageReductionDiscountCommand &operator=(
      const PackageReductionDiscountCommand &copy);
  public:
    PackageReductionDiscountCommand();
    PackageReductionDiscountCommand(
      std::string date,
      std::string client,
      std::vector<std::pair<std::string, float> > articles,
      std::map<std::string, float> article_prices);
    ~PackageReductionDiscountCommand();
    float get_total_price();
};