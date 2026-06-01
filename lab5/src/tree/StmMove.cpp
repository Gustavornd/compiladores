#include "StmMove.hpp"

StmMove *StmMove::gera_Stm_Move(Exp *destino, Exp *origem)
{
	StmMove *move = new StmMove();
	move->destino = destino;
	move->origem = origem;

	return move;
}

void StmMove::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "MOVE(" << endl;
	destino->debug(espacos + 1);
	origem->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
