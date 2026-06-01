#ifndef _STM_CJUMP_HPP_
#define _STM_CJUMP_HPP_
#include "Exp.hpp"
#include "Stm.hpp"
#include <string>
using namespace std;

class StmCJump : public Stm
{
	public:
	Exp *expressao_booleana;
	string destino_verdade;
	string destino_falso;
	StmCJump()
	{
	}
	static StmCJump *gera_Stm_CJump(Exp *exp, string label_true, string label_false);
	void debug(int espacos);
};

#endif
