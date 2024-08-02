/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:56:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 13:31:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
	
	private:
		Contact	contacts[MAX_CONTACTS];
		int		currentIndex;
		void	displayListContacts(void);
		void	selectContact(void);
};


#endif
