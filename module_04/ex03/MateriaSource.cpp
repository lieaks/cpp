#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		m_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource::~MateriaSource (){
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i])
			m_materia[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator= (const MateriaSource &rhs) {
	for (int i = 0; i < 4; i++)
		m_materia[i] = rhs.m_materia[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria* rhs){
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i] == NULL)
		{
			m_materia[i] = rhs;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (m_materia[i] && m_materia[i]->getType() == type)
			return m_materia[i]->clone();
	}
	return 0;
}