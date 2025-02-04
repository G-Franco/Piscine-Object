/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuesdayDiscount.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:54:39 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 15:41:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/thuesdayDiscount.hpp"

ThuesdayDiscountCommand::ThuesdayDiscountCommand() : Command() {}

ThuesdayDiscountCommand::ThuesdayDiscountCommand(
  std::string date,
  std::string client,
  std::vector<std::pair<std::string, float> > articles,
  std::map<std::string, float> article_prices)
  : Command(date, client, articles, article_prices) {}

ThuesdayDiscountCommand::ThuesdayDiscountCommand(
  const ThuesdayDiscountCommand &copy) : Command(copy) {}

ThuesdayDiscountCommand &ThuesdayDiscountCommand::operator=(
  const ThuesdayDiscountCommand &copy) {
  Command::operator=(copy);
  return *this;
}

ThuesdayDiscountCommand::~ThuesdayDiscountCommand() {}

// 10% discount on Tuesdays
float ThuesdayDiscountCommand::get_total_price() {
  float total = Command::get_total_price();
  if (_date.substr(0, 3) == "TUE") {
    total *= 0.9;
  }
  return total;
}
