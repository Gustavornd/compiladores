#include "StmExp.hpp"

StmExp *StmExp::gera_Stm_Exp(Exp *exp)
{
	StmExp *stm_exp = new StmExp();
	stm_exp->exp = exp;

	return stm_exp;
}

void StmExp::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "EXP(" << endl;
	exp->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
