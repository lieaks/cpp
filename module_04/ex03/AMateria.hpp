#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
	protected:

    public:
	AMateria();
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
};

#endif //AMATERIA_HPP