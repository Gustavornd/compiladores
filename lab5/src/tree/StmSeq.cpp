#include "StmSeq.hpp"

StmSeq *StmSeq::gera_Stm_Seq(Stm *esq, Stm *dir)
{
	StmSeq *seq = new StmSeq();

	seq->esq = esq;
	seq->dir = dir;

	return seq;
}

void StmSeq::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "SEQ(" << endl;
	if (esq)
		esq->debug(espacos + 1);

	if (dir)
		dir->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
