/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:38 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 13:34:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iomanip>
# include <iostream>
# include <string>
# include <sstream> 
# include <cstdlib>

# define MAX_CONTACTS 8

# define PINK		"\033[1;35m"
# define BLUE		"\033[1;34m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define LIGHT_BLUE	"\033[1;36m"
# define RESET		"\033[0m"

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool		isEmpty(void);
		void		fillContact(int *index);
		void		displayContactRow(int index);
		void		displayContactInformation(void);

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		int			enterField(std::string field, std::string *buff);
		void		displayField(std::string field_value);
};

#endif