/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:47:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 14:14:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

};

class	PreventNull {};
void	randomChump( std::string name );
void	randomChump(PreventNull* ptr);
Zombie*	newZombie( std::string name );
Zombie*	newZombie(PreventNull* ptr);

#endif
