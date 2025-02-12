/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singetons.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:11 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 11:29:11 by gacorrei         ###   ########.fr       */
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
    Singleton();
    Singleton(const Singleton &copy) = delete;
    Singleton &operator=(const Singleton &copy) = delete;

  public:
    // Static method to get the instance guarantees only one instance is created
    // If it's called more than once it will return the same instance
    // Static means it will persist through the program 
    // and is thread-safe (guaranteed by C++11)
    static Singleton &get_instance();
    const std::vector<T> &get_group() const;
    void add(const T &element);
    void remove(const T &element);
    const T &get_element(int index);
};
