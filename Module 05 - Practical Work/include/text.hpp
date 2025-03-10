/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:27:50 by gacorrei          #+#    #+#             */
/*   Updated: 2025/03/10 10:56:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Colours
constexpr const char *RESET = "\033[0m";
constexpr const char *RED = "\033[31m";
constexpr const char *GREEN = "\033[32m";
constexpr const char *BLUE = "\033[36m";
constexpr const char *YELLOW = "\033[33m";
constexpr const char *ORANGE = "\033[34m";
constexpr const char *MAGENTA = "\033[35m";

// Background colours
constexpr const char *BG_RED = "\033[41m";
constexpr const char *BG_GREEN = "\033[42m";
constexpr const char *BG_BLUE = "\033[46m";
constexpr const char *BG_YELLOW = "\033[43m";
constexpr const char *BG_ORANGE = "\033[44m";
constexpr const char *BG_MAGENTA = "\033[45m";

// Text styles
constexpr const char *BOLD = "\033[1m";
constexpr const char *UNDERLINE = "\033[4m";
constexpr const char *INVERSE = "\033[7m";
