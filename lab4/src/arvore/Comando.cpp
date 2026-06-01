#include "Comando.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Comando *Comando::extrai_comando(No_arv_parse *no)
{
	Comando *comando = new Comando();
	comando->expressao = Expressao::extrai_expressao(no->filhos[0]);
	// comando->debug();

	return comando;
}

Valor *Comando::calcula_valor(vector<Valor *> &params)
{
	return expressao->calcula_valor(params);
}

void Comando::checa_variaveis()
{
	expressao->checa_variaveis();
}

void Comando::carrega_frame(FrameFuncao *frame)
{
	expressao->carrega_frame(frame);
}
