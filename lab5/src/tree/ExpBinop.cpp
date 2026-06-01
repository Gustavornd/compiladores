#include "ExpBinop.hpp"
#include "Exp.hpp"

ExpBinop *ExpBinop::gera_Exp_Binop(Operador *op, Exp *esq, Exp *dir)
{
	ExpBinop *binop = new ExpBinop();
	binop->op = op;
	binop->esq = esq;
	binop->dir = dir;

	return binop;
}

void ExpBinop::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "BINOP(" << endl;
	op->debug(espacos + 1);
	esq->debug(espacos + 1);
	dir->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
