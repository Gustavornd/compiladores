#include "ExpEseq.hpp"
#include <iostream>
using namespace std;
ExpEseq *ExpEseq::gera_Exp_Eseq(Stm *stm, Exp *exp)
{
	ExpEseq *eseq = new ExpEseq();

	eseq->stm = stm;
	eseq->exp = exp;

	return eseq;
}

void ExpEseq::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "ESEQ(" << endl;
	exp->debug(espacos + 1);
	stm->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
