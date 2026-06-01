#ifndef _STM_JUMP_HPP_
#define _STM_JUMP_HPP_
#include "Exp.hpp"
#include "Stm.hpp"
#include <string>
#include <vector>
using namespace std;

class StmJump : public Stm
{
	public:
	Exp *destino;
	vector<string> alvos;
	StmJump()
	{
	}
	static StmJump *gera_Stm_Jump(Exp *dest, vector<string> alvos);
	void debug(int espacos);
};

#endif
