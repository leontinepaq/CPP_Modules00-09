/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:56:52 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 01:55:18 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		Cure& operator=(const Cure &src);
		~Cure();
		std::string const	&getType() const;
		Cure				*clone() const;
		void				use(ICharacter& target);
};

#endif
