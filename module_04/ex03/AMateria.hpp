#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string m_type;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &src);
	virtual ~AMateria();

	AMateria & operator = (const AMateria &rhs);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

private:
};

#endif //AMATERIA_HPP