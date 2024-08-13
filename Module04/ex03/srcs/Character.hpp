/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:02:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 02:11:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{	
	private:
		std::string	_name;
		AMateria	*_inventory[NB_MATERIA];

	public:
		Character(void);
		Character(std::string name);
		Character(const Character &src);
		Character& operator=(const Character &src);
		~Character(void);
		std::string const	&getName(void) const;
		size_t				getNbMateria(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				displayInventory(void) const;
		bool				_inInventory(AMateria *m) const;
};

#endif
