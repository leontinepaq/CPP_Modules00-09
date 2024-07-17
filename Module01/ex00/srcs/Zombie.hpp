/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:47:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/17 14:38:17 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);

	private:
		std::string name;
};

class	PreventNull {};
void	randomChump( std::string name );
void	randomChump(PreventNull* ptr);
Zombie*  newZombie( std::string name );
Zombie*  newZombie(PreventNull* ptr);

#endif
