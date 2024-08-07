/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:34:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 14:10:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string &filename, std::string &s1, std::string &s2)
{
	_filename = filename;
	_s1 = s1;
	_s2 = s2;
}

Sed::~Sed()
{
	if (_inStream.is_open())
		_inStream.close();
	if (_outStream.is_open())
		_outStream.close();
}

// static bool isDirectory(const std::string& path)
// {
// 	struct stat	buf;

// 	if (stat(path.c_str(), &buf) != 0)
// 		return false;
// 	return S_ISDIR(buf.st_mode);
// }

int Sed::openFiles(void)
{
	std::string newFile = _filename + ".replace";

	// if (isDirectory(_filename))
	// {
	// 	std::cerr << "Error: mySed: " << _filename << " is a directory" << std::endl;
	// 	return (1);
	// }
	_inStream.open(_filename.c_str());
	if (!_inStream.is_open())
	{
		std::cerr << "Error: mySed: could not open file: " << _filename << std::endl;
		return (1);
	}
	_outStream.open(newFile.c_str());
	if (!_outStream.is_open())
	{
		std::cerr << "Error: mySed: could not open file: " << newFile << std::endl;
		return (1);
	}
	return (0);
}

int	Sed::copyReplace(void)
{
	std::streamsize	size = _s1.size();
	std::streambuf	*streamBuf;
	char			tmp[size + 1];

	streamBuf = _inStream.rdbuf();
	tmp[size] = 0;
	while (streamBuf->in_avail() > size)
	{
		streamBuf->sgetn(tmp, size);
		if(_s1.compare(tmp) == 0)
			_outStream << _s2;
		else
		{
			streamBuf->pubseekoff(-size, std::ios_base::cur);
			_outStream << (char) streamBuf->sbumpc();
		}			
	}
	while (streamBuf->in_avail() > 0)
		_outStream << (char) streamBuf->sbumpc();
	return (0);
}

int Sed::mySed(std::string &filename, std::string &s1, std::string &s2)
{
	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: mySed: invalid arguments" << std::endl;
		return (1);
	}
	Sed Sed(filename, s1, s2);
	if (Sed.openFiles())
		return (1);
	if (Sed.copyReplace())
		return (1);
	return (0);
}
