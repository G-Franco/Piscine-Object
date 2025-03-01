/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:07:42 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/27 11:50:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <memory>

// Weak pointer can't be used with find, so we need to use owner_before
template <typename T>
bool weak_pointer_find(const std::vector<std::weak_ptr<T>> &vec, const std::weak_ptr<T> &ptr) {
  if (ptr.expired()) {
    return false;
  }

  for (const auto &entry : vec) {
    if (entry.expired()) {
      continue;
    }
    if (!entry.owner_before(ptr) &&
        !ptr.owner_before(entry)) {
      return true;
    }
  }
  return false;
}

template <typename T>
std::weak_ptr<T> weak_pointer_find_by_name(const std::vector<std::weak_ptr<T>> &vec, const std::string &name) {
  for (const auto &entry : vec) {
    if (entry.expired()) {
      continue;
    }
    auto ptr = entry.lock();
    if (ptr->get_name() == name) {
      return entry;
    }
  }
  return std::weak_ptr<T>();
}

template <typename T>
bool weak_pointer_erase(std::vector<std::weak_ptr<T>> &vec, const std::weak_ptr<T> &ptr) {
  if (ptr.expired()) {
    return false;
  }

  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it->expired()) {
      continue;
    }
    if (!it->owner_before(ptr) &&
        !ptr.owner_before(*it)) {
      vec.erase(it);
      return true;
    }
  }
  return false;
}

template <typename T>
std::shared_ptr<T> shared_pointer_get_by_name(const std::vector<std::shared_ptr<T>> &vec, const std::string &name) {
  if (name.empty()) {
    return nullptr;
  }
  for (const auto &entry : vec) {
    if (!entry) {
      continue;
    }
    if (entry->get_name() == name) {
      return entry;
    }
  }
  return nullptr;
}