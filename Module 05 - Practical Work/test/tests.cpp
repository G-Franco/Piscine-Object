/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:16:26 by gacorrei          #+#    #+#             */
/*   Updated: 2025/04/04 14:42:42 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File_checker.hpp"
#include "../include/text.hpp"
#include "../include/Time.hpp"
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

bool file_checker_error_cases() {
  std::filesystem::path nodes(NODE_BAD_FOLDER);
  std::filesystem::path trains(TRAIN_BAD_FOLDER);
  // These start at 1 to account for the non-existing file tests
  int node_count = 1;
  int train_count = 1;
  int node_errors = 0;
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

  if (node_errors == node_count &&
      train_errors == train_count) {
    std::cout << GREEN;
  }
  else {
    std::cout << RED;
  }
  std::cout << node_errors + train_errors << "/"
            << node_count + train_count << " tests passed" << RESET << "\n";
  return true;
}

int time_creation(int hours, int minutes, int seconds, bool expected, int &counter) {
  counter++;
  Time t(hours, minutes, seconds);
  if (t._hours == -1 ||
      t._minutes == -1 ||
      t._seconds == -1) {
    if (expected) {
      std::cout << GREEN << "Correctly detected error in time creation" << RESET << "\n";
      return 0;
    }
    else {
      std::cout << RED << "Error: Time creation failed when it shouldn't" << RESET << "\n";
      return 1;
    }
  }
  if (expected) {
    std::cout << RED << "Error: Time creation succeeded when it shouldn't" << RESET << "\n";
    return 1;
  }
  else {
    std::cout << GREEN << "Correctly created time" << RESET << "\n";
    return 0;
  }
}

int time_sum(Time t1, int duration, bool expected, int &counter) {
  counter++;
  try {
    t1 + duration;
    if (expected) {
      std::cout << RED << "Error: Time sum succeeded when it shouldn't" << RESET << "\n";
      return 1;
    }
    else {
      std::cout << GREEN << "Correctly summed time" << RESET << "\n";
      return 0;
    }
  }
  catch (const std::exception &e) {
    if (expected) {
      std::cout << GREEN << "Correctly detected error in time sum" << RESET << "\n";
      return 0;
    }
    else {
      std::cout << RED << "Error: Time sum failed when it shouldn't" << RESET << "\n";
      return 1;
    }
  }
}

int time_test() {
  int errors = 0;
  int test_cases = 0;
  std::cout << BOLD << "Testing time struct creation" << RESET << "\n";
  errors += time_creation(-1, 0, 0, true, test_cases);
  errors += time_creation(0, -1, 0, true, test_cases);
  errors += time_creation(0, 0, -1, true, test_cases);
  errors += time_creation(24, 0, 0, true, test_cases);
  errors += time_creation(0, 60, 0, true, test_cases);
  errors += time_creation(0, 0, 60, true, test_cases);
  errors += time_creation(0, 0, 0, false, test_cases);
  errors += time_creation(23, 59, 59, false, test_cases);
  errors += time_creation(1, 0, 0, false, test_cases);
  errors += time_creation(0, 1, 0, false, test_cases);
  errors += time_creation(0, 0, 1, false, test_cases);
  std::cout << BOLD << "-------------------------------------" << RESET << "\n";
  std::cout << BOLD << "Testing time sum" << RESET << "\n";
  errors += time_sum(Time(0, 0, 0), -1, true, test_cases);
  errors += time_sum(Time(0, 0, 0), 1, false, test_cases);
  errors += time_sum(Time(23, 59, 59), 1, false, test_cases);
  errors += time_sum(Time(23, 59, 59), 60, false, test_cases);
  errors += time_sum(Time(23, 59, 59), 3600, false, test_cases);
  errors += time_sum(Time(10, 10, 10), 0, false, test_cases);
  errors += time_sum(Time(10, 10, 10), 3600, false, test_cases);
  errors += time_sum(Time(10, 10, 10), 600, false, test_cases);
  errors += time_sum(Time(10, 10, 10), 60, false, test_cases);
  std::cout << BOLD << "-------------------------------------" << RESET << "\n";

  if (errors) {
    std::cout << RED << errors << "/" << test_cases << " tests failed" << RESET << "\n";
    return 1;
  }
  else {
    std::cout << GREEN << "All tests passed" << RESET << "\n";
    return 0;
  }
}

// TODO: Improve test structure
int main() {
  std::cout << BOLD << "Testing file_checker error cases" << RESET << "\n";
  file_checker_error_cases();
  std::cout << BOLD << "-------------------------------------" << RESET << "\n";

  std::cout << BOLD << "Testing time struct" << RESET << "\n";
  time_test();
}
