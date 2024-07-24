/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:12 by gacorrei          #+#    #+#             */
/*   Updated: 2024/07/24 17:12:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

// Use with output messages
// std::cout << RED << "ERROR..." << DEFAULT << "\n"
const std::string DEFAULT = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[36m";
const std::string ORANGE = "\033[34m";
const std::string YELLOW = "\033[33m";