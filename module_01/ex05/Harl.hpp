#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl;

typedef struct s_harl
{
	std::string level;
	void (Harl::*method)();
}	t_harl;

class Harl
{
	public:
	Harl();
	~Harl();
	void complain( std::string level );

	private:
	t_harl	m_harl[4];
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif //HARL_HPP