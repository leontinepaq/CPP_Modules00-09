/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:38 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/16 13:54:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

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

#endif