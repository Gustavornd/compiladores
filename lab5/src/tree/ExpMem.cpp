#include "ExpMem.hpp"
#include "Exp.hpp"

ExpMem *ExpMem::gera_Exp_Mem(Exp *endereco)
{
	ExpMem *mem = new ExpMem();
	mem->endereco = endereco;
	return mem;
}
void ExpMem::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "MEM(" << endl;
	endereco->debug(espacos + 1);
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
