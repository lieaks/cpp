#include "Harl.hpp"
#include <iostream>

Harl::Harl() 
{
	m_harl[0].level = "DEBUG";
	m_harl[1].level = "INFO";
	m_harl[2].level = "WARNING";
	m_harl[3].level = "ERROR";
	m_harl[0].method = &Harl::debug;	
	m_harl[1].method = &Harl::info;	
	m_harl[2].method = &Harl::warning;	
	m_harl[3].method = &Harl::error;	
}

Harl::~Harl(){}

void Harl::complain( std::string level )
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_harl[i].level == level)
		{
			idx = i;
			break ;
		}
		if (i == 3)
			idx = -1;
	}
	switch (idx)
	{
		case 0:
			(this->*m_harl[0].method)();
		case 1:
			(this->*m_harl[1].method)();
		case 2:
			(this->*m_harl[2].method)();
		case 3:
			(this->*m_harl[3].method)();
			break ;
		default:
			Harl::other();	
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
		<< "I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl
		<< "You didn’t put enough bacon in my burger!" << std::endl
		<< "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::other( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}