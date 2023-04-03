#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
protected:
	std::string m_type;

public:
	AMateria(std::string const & type);
	AMateria(const AMateria &src);
	~AMateria();

	AMateria & operator = (const AMateria &rhs);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

private:
	AMateria();
};

#endif //AMATERIA_HPP