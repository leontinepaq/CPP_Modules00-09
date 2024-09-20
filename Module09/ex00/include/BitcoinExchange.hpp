/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:45:40 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/18 15:14:55 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		
		std::map<std::string, double>	_dataBase;
		
		static void	openFile(std::string fileName, std::ifstream &input);
		static void	validateHeader(std::ifstream &is, std::string goodHeader);
		static int 	parseTransactionLine(std::string line, std::string &date, float &value);
		void		parseExchangeRate(std::string line, std::string &date, double &exchangeRate);
		void		loadExchangeRates();
		double		getBitcoinRateAtDate(std::string date);
		void		processInputFile(std::ifstream &input);
		void 		printBitcoinRate(std::string date, float value);

		class CantOpenFileException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidFileFormatException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
	public:
		static int	printBitcoinRatesFile(std::string file);
};

#endif
