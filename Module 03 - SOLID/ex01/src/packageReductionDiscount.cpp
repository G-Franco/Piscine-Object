/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packageReductionDiscount.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:00:43 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 12:03:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/packageReductionDiscount.hpp"

PackageReductionDiscountCommand::PackageReductionDiscountCommand() : Command() {}

PackageReductionDiscountCommand::PackageReductionDiscountCommand(std::string date, std::string client, std::vector<std::pair<std::string, float> > articles)
  : Command(date, client, articles) {}

PackageReductionDiscountCommand::PackageReductionDiscountCommand(const PackageReductionDiscountCommand &copy)
  : Command(copy) {}

PackageReductionDiscountCommand &PackageReductionDiscountCommand::operator=(const PackageReductionDiscountCommand &copy) {
  Command::operator=(copy);
  return *this;
}

PackageReductionDiscountCommand::~PackageReductionDiscountCommand() {}

float PackageReductionDiscountCommand::get_total_price() {
  float total = Command::get_total_price();
  if (total > 150) {
    total -= 10;
  }
return total;
}
