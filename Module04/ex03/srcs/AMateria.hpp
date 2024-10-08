/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:23:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 02:40:20 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

# define BLUE		"\033[1;34m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYAN		"\033[1;36m"
# define MAGENTA	"\033[1;35m"
# define YELLOW		"\033[1;33m"
# define GREY		"\033[1;30m"
# define WHITE		"\033[1;37m"
# define ORANGE		"\033[1;38;5;208m"
# define PURPLE		"\033[1;38;5;129m"
# define RESET		"\033[0m"

#define SHOW_CONSTRUCTORS 1
#define SHOW_ALL_MESSAGES 1

# define NB_MATERIA 4

class ICharacter;

class AMateria
{
	private:
		AMateria& operator=(const AMateria &src); // should not be used (https://www.developpez.net/forums/d2092233/c-cpp/cpp/classe-abstraite-operateur/)
	
	protected:
		std::string	_type;
		
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &src);
		virtual ~AMateria();
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
