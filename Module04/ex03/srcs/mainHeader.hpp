/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainHeader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:50 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/12 19:40:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINHEADER_HPP
# define MAINHEADER_HPP


#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
# include <sstream>
# include <iomanip>
# include <iostream>
# include <string>
# include <sstream> 

typedef struct s_params
{
	std::string name1;
	ICharacter* char1;
	std::string name2;
	ICharacter* char2;
	IMateriaSource* book;
} t_params;

void	help(void);
void	learn(t_params &params);
void	erase(t_params &params);
void	display(t_params &params);
void	equip(t_params &params);
void	unequip(t_params &params);
void	use(t_params params);

#endif