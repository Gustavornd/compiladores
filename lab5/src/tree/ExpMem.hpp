#ifndef _EXP_MEM_HPP_
#define _EXP_MEM_HPP_
#include "Exp.hpp"

class ExpMem : public Exp
{
	public:
	Exp *endereco;
	ExpMem()
	{
	}
	static ExpMem *gera_Exp_Mem(Exp *endereco);
	void debug(int espacos);
};

#endif
