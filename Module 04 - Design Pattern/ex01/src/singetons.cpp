/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singetons.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:10:21 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/12 11:29:15 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/singetons.hpp"

template <typename T>
Singleton<T>::Singleton() {}

template <typename T>
Singleton<T> &Singleton<T>::get_instance() {
  static Singleton instance;
  return instance;
}

template <typename T>
const std::vector<T> &Singleton<T>::get_group() const {
  return _group;
}

template <typename T>
void Singleton<T>::add(const T &element) {
  _group.push_back(element);
}

template <typename T>
void Singleton<T>::remove(const T &element) {
  _group.erase(element);
}

template <typename T>
const T &Singleton<T>::get_element(int index) {
  if (index < 0 || index >= _group.size()) {
    throw std::runtime_error("Index out of bounds");
  }
  return _group[index];
}
