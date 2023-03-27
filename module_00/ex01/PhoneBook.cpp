#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : m_index(-1) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(void)
{
	this->m_contacts[++m_index % 8].addInfo();
	if (m_index > 6)
		m_index = -1;
}

void	PhoneBook::searchMenu(void) const
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "firstname";
	std::cout << "|" << std::setw(10) << "lastname";
	std::cout << "|" << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	for(int i = 0; i <= m_index; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		m_contacts[i].viewInfo();
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "Please enter contact index desired or \"MENU\" to leave: " << std::endl;
	contactDetails();
}

void	PhoneBook::contactDetails() const
{
	std::string input("");

	while(42)
	{
		if(not input.compare("MENU"))
			return ;
		std::getline(std::cin, input); 
		if (std::cin.eof())
			exit (0);
		if (input.length() != 1 || !isdigit(input[0]) || stoi(input) < 0 || stoi(input) > m_index)
			std::cout << "Contact not found, please try again or enter \"MENU\"" << std::endl;
		else
			break ;
	}
	std::cout << "Index:\t\t" << stoi(input) << std::endl;
	this->m_contacts[stoi(input)].viewFullInfo();
}
