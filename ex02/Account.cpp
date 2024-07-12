// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Jul 11 19:43:15 2024                      //
//                Last update : Sun Jul 14 14:54:06 2024                      //
//                Made by :lpaquatt <marvin@42.fr                             //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	return ;
}
Account::~Account(void)
{
	return ;
}

std::string gettimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %X"); // Format the time
    return ss.str(); // Return the formatted string
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "[" << gettimestamp() << "] ";
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
}
