#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &src);
	~Ice();
	Ice & operator =(const Ice &rhs);
};

#endif //ICE_HPP