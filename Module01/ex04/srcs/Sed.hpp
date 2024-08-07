/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:27:15 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 14:08:07 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>
// #include <sys/stat.h>

class Sed
{
	public:
		static int mySed(std::string &filename, std::string &s1, std::string &s2);
		
	private:
		std::ifstream	_inStream;
		std::ofstream	_outStream;
		std::string		_filename;
		std::string		_s1;
		std::string		_s2;

		Sed(std::string &filename, std::string &s1, std::string &s2);
		~Sed();
		int 	openFiles(void);
		int		copyReplace(void);
};

#endif
