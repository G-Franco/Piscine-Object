/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singetons.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:11 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/23 19:12:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <memory>

template <typename T>
class Singleton {
  private:
    std::vector<std::shared_ptr<T> > _group;

    // Constructors are hidden so they can't be called
    Singleton() {}
    Singleton(const Singleton &copy) = delete;
    Singleton &operator=(const Singleton &copy) = delete;

  public:
    // Static method to get the instance guarantees only one instance is created
    // If it's called more than once it will return the same instance
    // Static means it will persist through the program 
    // and is thread-safe (guaranteed by C++11)
    static Singleton &get_instance() {
      static Singleton instance;
      return instance;
    }

    const std::vector<std::shared_ptr<T> > &get_group() const {
      return _group;
    }

    void add(std::shared_ptr<T> &element) {
      if (std::find(_group.begin(), _group.end(), element) != _group.end()) {
        std::cout << "Element already exists\n";
        return;
      }
      _group.push_back(element);
    }

    void remove(const std::shared_ptr<T> &element) {
      auto it = std::find(_group.begin(), _group.end(), element);
      if (it == _group.end()) {
        throw std::runtime_error("Element not found");
      }
      _group.erase(it);
    }

    std::shared_ptr<T> get_element(size_t index) {
      if (index >= _group.size()) {
        throw std::runtime_error("Index out of bounds");
      }
      return _group[index];
    }

    std::shared_ptr<T> find(const std::shared_ptr<T> &element) {
      if (std::find(_group.begin(), _group.end(), element) != _group.end()) {
        return element;
      }
      return nullptr;
    }

    // This requires the class to have an operator== overloaded to compare
    std::shared_ptr<T> find(const std::string info) {
      for (auto element : _group) {
        if (*element == info) {
          return element;
        }
      }
      return nullptr;
    }

    void clear() {
      _group.clear();
    }
};
