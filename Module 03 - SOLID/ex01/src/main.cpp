/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:04:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 15:44:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/thuesdayDiscount.hpp"
#include "../include/packageReductionDiscount.hpp"

int main() {
  std::map<std::string, float> prices;
  prices.insert(std::make_pair("apple", 0.5));
  prices.insert(std::make_pair("banana", 0.3));
  prices.insert(std::make_pair("orange", 0.4));
  prices.insert(std::make_pair("kiwi", 0.7));
  prices.insert(std::make_pair("grape", 0.6));
  prices.insert(std::make_pair("strawberry", 0.1));
  prices.insert(std::make_pair("blueberry", 0.2));
  prices.insert(std::make_pair("raspberry", 0.15));
  prices.insert(std::make_pair("blackberry", 0.25));
  prices.insert(std::make_pair("watermelon", 1.5));

  std::cout << "Testing basic cases\n";
  std::vector<std::pair<std::string, float> > articles;
  articles.push_back(std::make_pair("apple", 2));
  articles.push_back(std::make_pair("banana", 3));
  articles.push_back(std::make_pair("orange", 1));
  Command cmd1("MON_20250203", "John", articles, prices);
  ThuesdayDiscountCommand disc1("MON_20250203", "Jack", articles, prices);
  PackageReductionDiscountCommand disc2("MON_20250203", "James", articles, prices);
  std::cout << "[Command] Total price: " << cmd1.get_total_price() << "\n";
  std::cout << "[Tuesday discount] Total price: " << disc1.get_total_price() << "\n";
  std::cout << "[Package discount] Total price: " << disc2.get_total_price() << "\n";

  std::cout << "\nTesting Tuesday discount\n";
  Command cmd2("TUE_20250204", "Jane", articles, prices);
  ThuesdayDiscountCommand disc3("TUE_20250204", "Mary", articles, prices);
  PackageReductionDiscountCommand disc4("TUE_20250204", "Sue", articles, prices);
  std::cout << "[Command] Total price: " << cmd2.get_total_price() << "\n";
  std::cout << "[Tuesday discount] Total price: " << disc3.get_total_price() << "\n";
  std::cout << "[Package discount] Total price: " << disc4.get_total_price() << "\n";

  std::cout << "\nTesting package reduction discount\n";
  articles.push_back(std::make_pair("watermelon", 100));
  Command cmd3("WED_20250205", "Peckish", articles, prices);
  ThuesdayDiscountCommand disc5("WED_20250205", "Hungry", articles, prices);
  PackageReductionDiscountCommand disc6("WED_20250205", "Starving", articles, prices);
  std::cout << "[Command] Total price: " << cmd3.get_total_price() << "\n";
  std::cout << "[Tuesday discount] Total price: " << disc5.get_total_price() << "\n";
  std::cout << "[Package discount] Total price: " << disc6.get_total_price() << "\n";
  return 0;
}
