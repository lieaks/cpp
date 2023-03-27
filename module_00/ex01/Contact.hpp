#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
	Contact();
	~Contact();
	std::string	getInput(std::string str) const;
	void		addInfo();
	std::string menuFormat(std::string str) const;
	void		viewInfo() const;
	void		viewFullInfo() const;

	private:
	int			m_index;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_nickname;
	std::string m_phoneNumber;
	std::string m_darkestSecret;
};

#endif