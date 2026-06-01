#include "ExpName.hpp"
#include "Exp.hpp"

ExpName *ExpName::gera_Exp_Name(string nome)
{
	ExpName *name = new ExpName();
	name->nome = nome;

	return name;
}

void ExpName::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "NAME(" << nome << ")" << endl;
}
