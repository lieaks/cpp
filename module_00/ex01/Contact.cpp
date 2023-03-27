#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

std::string	Contact::getInput(std::string str) const
{
	std::string input("");

	while(1)
	{
		std::cout << "Please enter your " << str << ": " << std::flush;
		if (std::getline(std::cin, input) && !input.empty())
			break ;
		if (std::cin.eof())
			exit(0);
		else {
			std::cout << "Invalid " << str << ". try again." << std::endl;
		}
	}
	return input;
}

void	Contact::addInfo(void)
{
	this->m_firstName = getInput("first name"); 
	this->m_lastName= getInput("last name"); 
	this->m_nickname= getInput("nickname"); 
	this->m_phoneNumber= getInput("phone number"); 
	this->m_darkestSecret= getInput("darkest secret"); 
}

std::string Contact::menuFormat(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + "."; 
	return str;
}

void	Contact::viewInfo(void) const
{
	std::cout << "|" << std::setw(10) << menuFormat(m_firstName);
	std::cout << "|" << std::setw(10) << menuFormat(m_lastName);
	std::cout << "|" << std::setw(10) << menuFormat(m_nickname);
	std::cout << "|" << std::endl;
}

void	Contact::viewFullInfo(void) const
{
	std::cout << "First Name:\t" << m_firstName << std::endl;
	std::cout << "Last Name:\t" << m_lastName << std::endl;
	std::cout << "Nickname:\t" << m_nickname << std::endl;
	std::cout << "Phone Number:\t" << m_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << m_darkestSecret << std::endl;

}