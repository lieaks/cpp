#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchMenu() const;
	void contactDetails() const;

private:
	int		m_index;
	Contact m_contacts[8];
};

#endif