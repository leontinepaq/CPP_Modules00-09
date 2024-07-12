/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:56:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/12 16:01:16 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <limits>
# include <sstream> 

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool		is_empty(void);
		void		fill_contact(int *index);
		void		display_contact_list(int index);
		void		display_contact_information(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		int			enter_field(std::string field, std::string *buff);
		void		display_field(std::string field_value);
};

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		Contact	contacts[8];
		void	add(void);
		void	search(void);
	
	private:
		int		contact_to_write;
		void	display_list_contacts(void);
		void	select_contact(void);
};


#endif
