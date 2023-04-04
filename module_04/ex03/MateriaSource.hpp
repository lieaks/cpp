#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	virtual ~MateriaSource();
	MateriaSource & operator = (const MateriaSource &rhs);
	void learnMateria(AMateria*); 
	AMateria* createMateria(std::string const & type);

private:
	AMateria* m_materia[4];
};

#endif ///MATERIASOURCE_HPP