#ifndef _EXP_CONST_HPP_
#define _EXP_CONST_HPP_
#include "Exp.hpp"

class ExpConst : public Exp
{
	public:
	int valor;
	ExpConst()
	{
	}
	void debug(int espacos);
	static ExpConst *gera_Exp_Const(int valor);
};

#endif
