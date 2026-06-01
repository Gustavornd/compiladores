#ifndef _STM_MOVE_HPP_
#define _STM_MOVE_HPP_
#include "Exp.hpp"
#include "Stm.hpp"

class StmMove : public Stm
{
	public:
	Exp *destino;
	Exp *origem;
	StmMove()
	{
	}
	static StmMove *gera_Stm_Move(Exp *destino, Exp *origem);
	void debug(int espacos);
};

#endif
