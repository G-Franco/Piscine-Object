/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:16:26 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/13 15:00:29 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File_checker.hpp"
#include "../include/text.hpp"
#include <filesystem>

constexpr std::string_view NODE_GOOD_FILE = "files/nodes/good/test";
constexpr std::string_view TRAIN_GOOD_FILE = "files/trains/good/trains_subject";
constexpr std::string_view NODE_BAD_FOLDER = "files/nodes/bad";
constexpr std::string_view TRAIN_BAD_FOLDER = "files/trains/bad";

// Type: 0 = file, 1 = directory
bool check_path(const std::filesystem::path &path, int type) {
  if (!std::filesystem::exists(path))
  {
    std::cout << RED << "Error: " << path << " does not exist" << RESET << "\n";
    return false;
  }
  if (type == 0 && !std::filesystem::is_regular_file(path)) {
    std::cout << RED << "Error: " << path << " is not a file" << RESET << "\n";
    return false;
  }
  if (type == 1 && !std::filesystem::is_directory(path)) {
    std::cout << RED << "Error: " << path << " is not a directory" << RESET << "\n";;
    return false;
  }
  return true;
}

void count_test_files(const std::filesystem::path &path, int& count) {
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    if (entry.is_regular_file()) {
      count++;
    }
  }
  std::cout << BLUE << "Number of files in " << path << ": " << count << RESET << "\n";
  return;
}

void test_errors_msg(const std::string &file_name, bool error, int &errors) {
  if (error) {
    std::cout << GREEN << "Correctly detected errors in " << file_name << RESET << "\n";
    errors++;
  }
  else {
    std::cout << RED << "Error: " << file_name << " did not detect errors"  << RESET << "\n";
  }
}

void test_nodes(const std::filesystem::path &path, int &errors) {
  if (errors != 0) {
    return;
  }
  // Testing empty path
  {
    std::cout << "\n";
    std::string path_str = "";
    File_checker fc(path_str, std::string(TRAIN_GOOD_FILE));
    test_errors_msg(path_str, !fc.validate_files(), errors);
  }

  for (auto &entry : std::filesystem::directory_iterator(path)) {
    std::string path_str = entry.path().string();
    std::cout << BOLD << "\nTesting file: " << entry << RESET << "\n";
    File_checker fc(path_str, std::string(TRAIN_GOOD_FILE));
    test_errors_msg(path_str, !fc.validate_files(), errors);
  }
  return;
}

void test_trains(const std::filesystem::path &path, int &errors) {
  if (errors != 0) {
    return;
  }
  // Testing empty path
  {
    std::cout << "\n";
    std::string path_str = "";
    File_checker fc(std::string(NODE_GOOD_FILE), path_str);
    test_errors_msg(path, !fc.validate_files(), errors);
  }

  for (auto &entry : std::filesystem::directory_iterator(path)) {
    std::string path_str = entry.path().string();
    std::cout << BOLD << "\nTesting file: " << entry << RESET << "\n";
    File_checker fc(std::string(NODE_GOOD_FILE), path_str);
    test_errors_msg(path_str, !fc.validate_files(), errors);
  }
  return;
}

// TODO: Add more test files for this case
bool file_checker_error_cases() {
  std::filesystem::path nodes(NODE_BAD_FOLDER);
  std::filesystem::path trains(TRAIN_BAD_FOLDER);
  int node_count = 0;
  int node_errors = 0;
  int train_count = 0;
  int train_errors = 0;

  if (!check_path(NODE_BAD_FOLDER, 1) ||
      !check_path(TRAIN_BAD_FOLDER, 1) ||
      !check_path(NODE_GOOD_FILE, 0) ||
      !check_path(TRAIN_GOOD_FILE, 0)) {
    return false;
  }
  count_test_files(nodes, node_count);
  count_test_files(trains, train_count);
  test_nodes(nodes, node_errors);
  test_trains(trains, train_errors);

  // Need to add 1 to the count to account for the non-existing file tests
  if (node_errors == node_count + 1 &&
      train_errors == train_count + 1) {
    std::cout << GREEN;
  }
  else {
    std::cout << RED;
  }
  std::cout << node_count + train_count << "/"
            << node_count + train_count << " tests passed" << RESET << "\n";
  return true;
}

int main() {
  return file_checker_error_cases();
}
