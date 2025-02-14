/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singetons.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:11 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 14:49:59 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>

template <typename T>
class Singleton {
  private:
    std::vector<T> _group;

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

    const std::vector<T> &get_group() const {
      return _group;
    }

    void add(const T &element) {
      _group.push_back(element);
    }

    void remove(const T &element) {
      auto it = std::find(_group.begin(), _group.end(), element);
      if (it == _group.end()) {
        throw std::runtime_error("Element not found");
      }
      _group.erase(it);
    }

    const T &get_element(size_t index) {
      if (index >= _group.size()) {
        throw std::runtime_error("Index out of bounds");
      }
      return _group[index];
    }
};
