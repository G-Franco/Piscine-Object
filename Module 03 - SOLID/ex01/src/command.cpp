/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:17:13 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 11:53:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command.hpp"

int Command::_id = 0;

Command::Command() {
  _id = Command::_id++;
  prepare_articles();
}

Command::Command(std::string date, std::string client, std::vector<std::pair<std::string, float> > articles) {
  _id = Command::_id++;
  _date = validate_date(date);
  _client = client;
  _articles = articles;
  prepare_articles();
  validate_articles();
}

Command::Command(const Command &copy)
  : _date(copy._date),
    _client(copy._client),
    _articles(copy._articles) {
  _id = copy._id;
  prepare_articles();
}

Command &Command::operator=(const Command &copy) {
  _id = copy._id;
  _date = copy._date;
  _client = copy._client;
  _articles = copy._articles;
  return *this;
}

Command::~Command() {}

void Command::prepare_articles() {
  article_prices.insert(std::make_pair("apple", 0.5));
  article_prices.insert(std::make_pair("banana", 0.3));
  article_prices.insert(std::make_pair("orange", 0.4));
  article_prices.insert(std::make_pair("kiwi", 0.7));
  article_prices.insert(std::make_pair("grape", 0.6));
  article_prices.insert(std::make_pair("strawberry", 0.1));
  article_prices.insert(std::make_pair("blueberry", 0.2));
  article_prices.insert(std::make_pair("raspberry", 0.15));
  article_prices.insert(std::make_pair("blackberry", 0.25));
  article_prices.insert(std::make_pair("watermelon", 1.5));
}

void Command::validate_articles() {
  int len = _articles.size();
  for (int i = 0; i < len; i++) {
    if (article_prices.find(_articles[i].first) == article_prices.end()) {
      throw std::runtime_error("Invalid article: " + _articles[i].first + "\n");
    }
  }
}

void Command::set_date(std::string date) {
  _date = validate_date(date);
}

void Command::set_client(std::string client) {
  _client = client;
}

void Command::add_article(std::string article, float quantity) {
  _articles.push_back(std::make_pair(article, quantity));
}

float Command::get_total_price() {
  float total = 0;
  int len = _articles.size();
  for (int i = 0; i < len; i++) {
    total += article_prices[_articles[i].first] * _articles[i].second;
  }
  return total;
}

// Date format: WDY_YYYYMMDD
// WDY: Weekday
std::string Command::validate_date(std::string date) {
  if (date.length() != 12 || date[3] != '_') {
    throw std::runtime_error(DATE_FORMAT_ERR);
  }
  std::string weekday_ss = date.substr(0, 3);
  std::istringstream year_ss(date.substr(4, 4));
  std::istringstream month_ss(date.substr(8, 2));
  std::istringstream day_ss(date.substr(10, 2));
  int year;
  int month;
  int day;
  if (!(year_ss >> year) ||
      !(month_ss >> month) ||
      !(day_ss >> day)) {
    throw std::runtime_error(DATE_FORMAT_ERR);
  }
  if (month < 1 || month > 12) {
    throw std::runtime_error(DATE_FORMAT_ERR);
  }
  std::string weekdays[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  for (int i = 0; i < 7; i++)
  {
    if (weekday_ss == weekdays[i]) {
      break;
    }
    if (i == 6) {
      throw std::runtime_error(DATE_FORMAT_ERR);
    }
  }
  // Index 0 is not used
  int max_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (leap_year(year)) {
    max_days[2] = 29;
  }
  if (day < 1 || day > max_days[month]) {
    throw std::runtime_error(DATE_FORMAT_ERR);
  }
  return date;
}

bool Command::leap_year(int year) {
  if (year % 4)
		return false;
	else if (year % 100)
		return true;
	else if (year % 400)
		return false;
	else
		return true;
}
