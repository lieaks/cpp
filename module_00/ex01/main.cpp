#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string input("");

	while(42)
	{
		std::cout << std::endl << "-----------PHONEBOOK'S MENU-----------" << std::endl;
		std::cout << "ADD    : to save a new contact" << std::endl;
		std::cout << "SEARCH : to display a specific contact" << std::endl;
		std::cout << "EXIT   : to quit";
		std::cout << std::endl << "--------------------------------------" << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof())
			return 0;
		if (not input.compare("ADD"))
		{
			phonebook.addContact();
		}
		else if (not input.compare("SEARCH"))
		{
			phonebook.searchMenu();
		}
		else if (not input.compare("EXIT"))
			break ;
		else
			std::cout << "/!\\ -> Wrong command, try again <- /!\\" << std::endl;
	}
	return 0;
}