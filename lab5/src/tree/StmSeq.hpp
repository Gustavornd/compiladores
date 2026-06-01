#pragma once
#include "Stm.hpp"

class StmSeq : public Stm
{
	public:
	Stm *esq;
	Stm *dir;
	StmSeq()
	{
	}
	static StmSeq *gera_Stm_Seq(Stm *esq, Stm *dir);
	void debug(int espacos);
};
