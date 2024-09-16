/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:04:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/16 17:24:53 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

class Colors {
public:
    static const std::string RED;
    static const std::string GREEN;
    static const std::string CYAN;
    static const std::string MAGENTA;
    static const std::string YELLOW;
    static const std::string GREY;
    static const std::string WHITE;
    static const std::string ORANGE;
    static const std::string PURPLE;
    static const std::string BLUE;
    static const std::string RESET;
};

const std::string Colors::RED = "\033[1;31m";
const std::string Colors::GREEN = "\033[1;32m";
const std::string Colors::CYAN = "\033[1;36m";
const std::string Colors::MAGENTA = "\033[1;35m";
const std::string Colors::YELLOW = "\033[1;33m";
const std::string Colors::GREY = "\033[1;30m";
const std::string Colors::WHITE = "\033[1;37m";
const std::string Colors::ORANGE = "\033[1;38;5;208m";
const std::string Colors::PURPLE = "\033[1;38;5;129m";
const std::string Colors::BLUE = "\033[1;34m";
const std::string Colors::RESET = "\033[0m";

#endif