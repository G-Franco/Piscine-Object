/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:51:51 by gacorrei          #+#    #+#             */
/*   Updated: 2024/12/30 11:32:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../include/Worker.hpp"

class Workshop {
  private:
    std::vector<Worker *> _workers;
    Workshop(const Workshop &copy);
    Workshop &operator=(const Workshop &copy);
  public:
    Workshop();
    ~Workshop();
    void add_worker(Worker *worker);
    void remove_worker(Worker *worker);
    void executeWorkDay();
};
