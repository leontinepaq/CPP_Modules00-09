/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:51:23 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/11 16:29:42 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <algorithm>



BitcoinExchange::BitcoinExchange()
{
	std::cout << GREY << "[BitcoinExchange] Default constructor called" << RESET << std::endl;
	loadExchangeRates();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _dataBase(src._dataBase)
{
	std::cout << GREY << "[BitcoinExchange] Copy constructor called" << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	std::cout << GREY << "[BitcoinExchange] Assignment operator called" << RESET << std::endl;
	_dataBase = src._dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREY << "[BitcoinExchange] Destructor called" << RESET << std::endl;
}

void	BitcoinExchange::openFile(std::string fileName, std::ifstream &input)
{
	input.open(fileName.c_str());
	if (!input.is_open())
		throw (CantOpenFileException());
}

void	BitcoinExchange::validateHeader(std::ifstream &is, std::string goodHeader)
{
	std::string header;
	getline(is, header);
	if (header != goodHeader)
		throw (InvalidFileFormatException());
}

static bool	validateDateFormat(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::stringstream ss(date);
	int year, month, day;
	char c1, c2;
	ss >> year >> c1 >> month >> c2 >> day;
	if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
        return false;
	if (year < 1900 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
	 	return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > 29 || (day == 29 && !isLeap))
			return false;
	}
	return true;
}

static bool	validateExchangeRateFormat(std::string exchangeRate)
{
	std::stringstream ss(exchangeRate);
	double exchangeRateDouble;
	ss >> std::noskipws >> exchangeRateDouble;
	if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
		return false;
	return true;
}

static bool	validateValueFormat(std::string value)
{
	std::stringstream ss(value);
	float valueFloat;
	ss >> std::noskipws >> valueFloat;
	if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
	{
		std::cout << RED << "Error: bad input => " << value << RESET << std::endl;
		return false;
	}
	if (valueFloat < 0)
	{
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	if (valueFloat > 1000)
	{
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	return true;
}

 void	BitcoinExchange::parseExchangeRate(std::string line, std::string &date, double &exchangeRate)
{
	std::istringstream lineStream(line);
	std ::string exchangeRateStr;
	getline(lineStream, date, ',');
	getline(lineStream, exchangeRateStr);
	if (!validateDateFormat(date) || !validateExchangeRateFormat(exchangeRateStr))
		throw (BitcoinExchange::InvalidFileFormatException());
	std::stringstream ss(exchangeRateStr);
	ss >> exchangeRate;
}

void	BitcoinExchange::loadExchangeRates()
{
	std::ifstream data;
	openFile("data.csv", data);
	validateHeader(data, "date,exchange_rate");
	while (data)
	{
		std::string	line;
		getline(data, line);
		if (line.empty())
			continue;
		std::string date;
		double exchangeRate;
		parseExchangeRate(line, date, exchangeRate);
		_dataBase[date] = exchangeRate;
	}
}

double	BitcoinExchange::getBitcoinRateAtDate(std::string date)
{
	std::map<std::string, double>::iterator it;
	if (_dataBase.empty() || _dataBase.begin()->first > date)
		return 0;
	for (it = _dataBase.begin(); it != _dataBase.end(); it++)
		if (it->first > date)
			break;
	it--;
	return it->second;
}

int 	BitcoinExchange::parseTransactionLine(std::string line, std::string &date, float &value)
{
	if (line.empty())
		return 1;
	std::istringstream lineStream(line);
	std::string valueStr;
	std::string	sep;
	getline(lineStream, date, ' ');
	getline(lineStream, sep, ' ');
	getline(lineStream, valueStr);
	if (sep != "|" || validateDateFormat(date) == false)
	{
		std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
		return 1;
	}
	if (!validateValueFormat(valueStr))
		return 1;
	std::stringstream ss(valueStr);
	ss >> value;
	return 0;
}

void	BitcoinExchange::printBitcoinRate(std::string date, float value)
{
	double btcRate = getBitcoinRateAtDate(date);
	std::cout << date << " => " << value << " = " << std::abs(btcRate * value) << std::endl;
}

void	BitcoinExchange::processInputFile(std::ifstream &input)
{
	while (input)
	{
		std::string line;
		getline(input, line);
		std::string date;
		float value;
		if (parseTransactionLine(line, date, value))
			continue;
		printBitcoinRate(date, value);
	}
}

int	BitcoinExchange::printBitcoinRatesFile(std::string file)
{
	try
	{
		std::ifstream input;
		openFile(file, input);
		validateHeader(input, "date | value");
		BitcoinExchange	btc;
		btc.processInputFile(input);
	}
	catch (BitcoinExchange::CantOpenFileException &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	catch (BitcoinExchange::InvalidFileFormatException &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;          
}

const char* BitcoinExchange::CantOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return "Error: file format is not valid.";
}
