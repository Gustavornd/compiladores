#include "StmJump.hpp"
#include "Stm.hpp"

StmJump *StmJump::gera_Stm_Jump(Exp *dest, vector<string> alvos)
{
	StmJump *jmp = new StmJump();

	jmp->destino = dest;
	jmp->alvos = alvos;

	return jmp;
}

void StmJump::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "JUMP(" << endl;
	destino->debug(espacos + 1);
	for (int i = 0; i < alvos.size(); i++)
	{
		for (int i = 0; i < espacos + 1; i++)
		{
			cout << " ";
		}
		cout << alvos[i] << ";" << endl;
	}
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
