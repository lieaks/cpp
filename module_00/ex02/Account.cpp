#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;

}

void	Account::makeDeposit( int deposit )
{
	if (deposit > 0)
	{
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex 
			<< ";p_amount:" << _amount - deposit
			<< ";deposit:" << deposit
			<< ";amount:" << _amount 
			<< ";nb_deposits:" << _nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= checkAmount() && withdrawal > 0)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex 
			<< ";p_amount:" << _amount + withdrawal
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
	return false;
}
int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			<< ";amount:" << _amount 
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t time = std::time(NULL);
	struct tm *timefull = std::localtime(&time);

	std::cout << std::setfill('0') << "[" << 1900 + timefull->tm_year
		<< std::setw(2) << 1 + timefull->tm_mon
		<< std::setw(2) << timefull->tm_mday << "_"
		<< std::setw(2) << timefull->tm_hour
		<< std::setw(2) << timefull->tm_min
		<< std::setw(2) << timefull->tm_sec << "] ";
}
