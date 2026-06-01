#ifndef _EXP_TEMP_HPP_
#define _EXP_TEMP_HPP_
#include "Exp.hpp"

class ExpTemp : public Exp
{
	public:
	int id;
	static ExpTemp *gera_Exp_Temp(int id);
	void debug(int espacos);
	ExpTemp()
	{
	}
};

#endif
