/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:55:25 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 13:49:37 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat(void);
		void 		makeSound(void) const;
		void 		setIdea(int i, std::string idea);
		std::string getIdea(int i) const;

	private:
		Brain *_brain;
};

#endif
