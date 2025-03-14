/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_checker.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:32:34 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/12 15:17:36 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <memory>

struct Rail;
class Train;
class AValidation;

class File_checker {
  private:
    std::ifstream _rail_file;
    std::ifstream _train_file;
    std::vector<std::string> _nodes;
    std::vector<Rail> _rails;
    std::vector<Train> _trains;
    std::unordered_map<std::string, std::vector<Rail*>> _network;
    std::vector<std::pair<std::unique_ptr<AValidation>, std::ifstream &>> _steps;

  public:
    File_checker(const std::string &rail_file, const std::string &train_file);
    File_checker(const File_checker &copy) = delete;
    File_checker &operator=(const File_checker &copy) = delete;
    ~File_checker();
    bool validate_files();
    bool check_file(std::ifstream &file, const std::string &file_name);
    void set_validation_steps();
    void make_network();
    bool validate_network();
    void test_print();
};
