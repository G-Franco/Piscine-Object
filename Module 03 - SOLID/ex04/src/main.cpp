/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:50:46 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 14:25:15 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/to_file_logger.hpp"
#include "../include/to_ostream_logger.hpp"
#include "../include/header_date_logger.hpp"
#include "../include/header_text_logger.hpp"
#include <vector>

void clean_up(std::vector<ILogger*> &loggers) {
  for (size_t i = 0; i < loggers.size(); i++) {
    delete loggers[i];
  }
}

int main() {
  std::vector<std::string> messages;
  messages.push_back("Log message 1");
  messages.push_back("Log message 2");
  messages.push_back("Log message 3");
  messages.push_back("Log message 4");
  messages.push_back("Log message 5");

  std::vector<ILogger*> loggers;
  try {
    loggers.push_back(new to_file_logger("log.txt"));
    loggers.push_back(new to_ostream_logger(std::cout));
    loggers.push_back(new header_date_logger(*loggers[0]));
    loggers.push_back(new header_date_logger(*loggers[1]));
    loggers.push_back(new header_text_logger(*loggers[0], "Header1: "));
    loggers.push_back(new header_text_logger(*loggers[1], "Header2: "));

    for (size_t i = 0; i < messages.size(); i++) {
      for (size_t j = 0; j < loggers.size(); j++) {
        loggers[j]->write(messages[i]);
      }
    }
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    clean_up(loggers);
    return 1;
  }
  clean_up(loggers);
  return 0;
}
