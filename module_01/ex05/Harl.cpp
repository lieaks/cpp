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
	for (int i = 0; i < 4; i++)
	{
		if (m_harl[i].level == level)
		{
			(this->*m_harl[i].method)();
		}
	}
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}