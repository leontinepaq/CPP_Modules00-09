/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:27:15 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/19 16:41:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>


class Sed
{
	public:
		static int mySed(std::string &filename, std::string &s1, std::string &s2);
		
	private:
		std::ifstream	infile;
		std::ofstream	outfile;
		std::string		filename;
		std::string		s1;
		std::string		s2;
		std::string		line;

		Sed(std::string &filename, std::string &s1, std::string &s2);
		~Sed();
		int 	openFiles();
		int		copyReplace();
		int		replaceLine();
};

#endif
