#include "StmCJump.hpp"
#include "Stm.hpp"

StmCJump *StmCJump::gera_Stm_CJump(Exp *exp, string label_true, string label_false)
{
	StmCJump *cjump = new StmCJump();
	cjump->expressao_booleana = exp;
	cjump->destino_verdade = label_true;
	cjump->destino_falso = label_false;
	return cjump;
}
void StmCJump::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "CJUMP(true: " << destino_verdade << " ; false: " << destino_falso << endl;
	expressao_booleana->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
