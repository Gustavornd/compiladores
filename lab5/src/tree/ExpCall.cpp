#include "ExpCall.hpp"

ExpCall *ExpCall::gera_Exp_Call(Exp *nome_funcao, vector<Exp *> params)
{
	ExpCall *exp = new ExpCall();
	exp->nome_funcao = nome_funcao;
	exp->parametros = params;
	return exp;
}
void ExpCall::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "CALL(" << endl;
	nome_funcao->debug(espacos + 1);

	for (int i = 0; i < parametros.size(); i++)
	{
		parametros[i]->debug(espacos + 1);
	}
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << ")" << endl;
}
