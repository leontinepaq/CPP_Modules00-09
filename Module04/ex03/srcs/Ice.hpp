/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:23:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 18:11:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
		std::string	_type;
		
	public:
		Ice();
		Ice(const Ice &src);
		Ice& operator=(const Ice &src);
		~Ice();
		std::string const	&getType() const; //Returns the materia type
		Ice					*clone() const;
		void				use(ICharacter& target);
};

#endif
