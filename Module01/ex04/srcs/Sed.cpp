/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:34:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/19 16:47:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


Sed::Sed(std::string &filename, std::string &s1, std::string &s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

Sed::~Sed()
{
	if (this->infile.is_open())
		this->infile.close();
	if (this->outfile.is_open())
		this->outfile.close();
}

static bool isDirectory(const std::string& path)
{
	struct stat	buf;

	if (stat(path.c_str(), &buf) != 0)
		return false;
	return S_ISDIR(buf.st_mode);
}

int Sed::openFiles()
{
	std::string newFile = this->filename + ".replace";

	if (isDirectory(this->filename))
	{
		std::cerr << "Error: mySed: " << this->filename << " is a directory" << std::endl;
		return (EXIT_FAILURE);
	}
	this->infile.open(this->filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: mySed: could not open file: " << this->filename << std::endl;
		return (EXIT_FAILURE);
	}
	this->outfile.open(newFile.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: mySed: could not open file: " << newFile << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


int Sed::replaceLine()
{
	size_t		index = 0;
	std::string	newLine;
	

	while (line[index])
	{
		if (line.substr(index, this->s1.length()) == this->s1)
		{
			newLine += this->s2;
			index += this->s1.length();
		}
		else
		{
			newLine += line[index];
			index++;
		}
	}
	this->line = newLine;
	return (EXIT_SUCCESS);	
}


int Sed::copyReplace()
{
	while (getline(this->infile, this->line))
	{
		this->replaceLine();
		this->outfile << this->line;
		if (!this->infile.eof())
		 	this->outfile << std::endl;
	}
	return (EXIT_SUCCESS);

}

int Sed::mySed(std::string &filename, std::string &s1, std::string &s2)
{
	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: mySed: invalid arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	Sed Sed(filename, s1, s2);
	if (Sed.openFiles())
		return (EXIT_FAILURE);
	if (Sed.copyReplace())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
