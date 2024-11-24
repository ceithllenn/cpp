#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

/******************************************************
			STATIC VARIABLES
******************************************************/
/*Accounts created*/
int Account::_nbAccounts = 0;

/*Total money on all accounts*/
int Account::_totalAmount = 0;

/*Total number of deposits on all accounts*/
int Account::_totalNbDeposits = 0;

/*Total number of withdrawals on all accounts*/
int Account::_totalNbWithdrawals = 0;

/*
 * Account class default constructor
 */
Account::Account(void)
{

}

/*
 * Account class default destructor
 */
Account::~Account(void)
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

/*
 * Account class constructor
 *
 * @param initial_deposit Account._amount
 */
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
}

/*
 * Account class getters
 */

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/*
 * displays general infos an all accounts
 */
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
			<< "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

/*
 * Makes a deposit into an account
 *
 * @param deposit amount to depose
 */
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

int Account::checkAmount(void) const
{
	return (_amount);
}

/*
 * Makes a widhdrawal to an account if possible
 *
 * @param widthdrawal amount to withdraw
 * @return false if withdrawal is impossible
 */
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:";
	if (checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout
			<< withdrawal
			<< ";amount:" << _amount
			<< ";nb_widthdrawals:" << _nbWithdrawals
			<< std::endl;
	return (true);
}

/*
 * displays information about a single account
 */
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

/*
 * displays time
 */
void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);
	std::tm now = *std::localtime(&time);
	std::cout
		<< "["
		<< (now.tm_year + 1900)
		<< std::setfill('0')
		<< std::setw(2) << now.tm_mon + 1
		<< std::setw(2) << now.tm_mday << "_"
		<< std::setw(2) << now.tm_hour
		<< std::setw(2) << now.tm_min
		<< std::setw(2) << now.tm_sec
		<< "] ";
}
