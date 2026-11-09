#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	if (ltm->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << ltm->tm_mon + 1;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout << ltm->tm_mday << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout << ltm->tm_sec << "] ";
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
	          << "total:" << _totalAmount << ";"
	          << "deposits:" << _totalNbDeposits << ";"
	          << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:";
	if (withdrawal < 0 || this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (0);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}
