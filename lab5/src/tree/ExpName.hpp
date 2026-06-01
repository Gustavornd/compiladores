#ifndef _EXP_NAME_HPP_
#define _EXP_NAME_HPP_
#include "Exp.hpp"

class ExpName : public Exp
{
	public:
	string nome;
	static ExpName *gera_Exp_Name(string nome);
	void debug(int espacos);
	ExpName()
	{
	}
};

#endif
