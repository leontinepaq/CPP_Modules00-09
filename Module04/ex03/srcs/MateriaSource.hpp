/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:24:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/12 21:58:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[NB_MATERIA];
	
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource(void);
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
		void		eraseMateria(int idx);
		void		displayKnownMaterias(void) const;
};

#endif
