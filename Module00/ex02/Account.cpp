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
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdio>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_totalAmount -= this->_amount;
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (checkAmount() < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << checkAmount() << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() + withdrawal << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) 
{
    char buffer[16];
    std::time_t now = std::time(NULL);
    std::tm* now_tm = std::localtime(&now);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now_tm);
	std::cout << "[" << buffer << "] ";
    return ;
}
