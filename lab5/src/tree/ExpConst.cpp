#include "ExpConst.hpp"

void ExpConst::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "CONST(" << valor << ")" << endl;
}

ExpConst *ExpConst::gera_Exp_Const(int valor)
{
	ExpConst *c = new ExpConst();
	c->valor = valor;
	return c;
}
