#ifndef _STM_EXP_HPP_
#define _STM_EXP_HPP_
#include "Exp.hpp"
#include "Stm.hpp"

using namespace std;
class StmExp : public Stm
{
	public:
	Exp *exp;
	StmExp()
	{
	}
	static StmExp *gera_Stm_Exp(Exp *exp);
	void debug(int espacos);
};

#endif
