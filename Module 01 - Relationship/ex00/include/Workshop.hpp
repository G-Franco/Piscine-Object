/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:51:51 by gacorrei          #+#    #+#             */
/*   Updated: 2025/01/07 11:46:05 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Worker.hpp"

class Worker;

class Workshop {
  private:
    std::vector<Worker *> _workers;
    std::string _tool_type;
    Workshop(const Workshop &copy);
    Workshop &operator=(const Workshop &copy);
  public:
    Workshop();
    Workshop(std::string tool_type);
    ~Workshop();
    std::string get_tool_type() const;
    void add_worker(Worker *worker);
    void remove_worker(Worker *worker);
    void executeWorkDay();
};
