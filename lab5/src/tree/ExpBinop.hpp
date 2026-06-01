#ifndef _EXP_BINOP_HPP_
#define _EXP_BINOP_HPP_
#include "Exp.hpp"
#include "Operador.hpp"

class ExpBinop : public Exp
{
	public:
	Operador *op;
	Exp *esq;
	Exp *dir;
	void debug(int espacos);
	ExpBinop()
	{
	}
	static ExpBinop *gera_Exp_Binop(Operador *op, Exp *esq, Exp *dir);
};

#endif
