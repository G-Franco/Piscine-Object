/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:28:57 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/04 11:53:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#define DATE_FORMAT_ERR "Invalid date format. Please use WKD_YYYYMMDD. (WKD: Weekday)"


class Command {
  protected:
    static int _id;
    std::string _date;
    std::string _client;
    // Article name and quantity
    std::vector<std::pair<std::string, float> > _articles;
    std::map<std::string, float> article_prices;

    Command(const Command &copy);
    Command &operator=(const Command &copy);
    void prepare_articles();

  public:
    Command();
    Command(std::string date, std::string client, std::vector<std::pair<std::string, float> > articles);
    virtual ~Command();
    // const int get_id() const;
    void set_date(std::string date);
    // const int get_client() const;
    void set_client(std::string client);
    // const std::vector<std::pair<std::string, float> > get_articles() const;
    void add_article(std::string article, float quantity);
    virtual float get_total_price();
    std::string validate_date(std::string date);
    bool leap_year(int year);
    void validate_articles();
};
