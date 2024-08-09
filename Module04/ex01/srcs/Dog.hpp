/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:31:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 13:49:50 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();
		void		makeSound(void) const;
		void 		setIdea(int i, std::string idea);
		std::string getIdea(int i) const;

	private:
		Brain *_brain;
};

#endif