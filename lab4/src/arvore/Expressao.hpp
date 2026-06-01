#pragma once
#define EXPRESAO_HPP
#include "../Arvore.hpp"
#include "Variavel.hpp"
#include <iostream>
using namespace std;

class FrameFuncao;

class Expressao
{
	public:
	Expressao()
	{
	}
	~Expressao()
	{
	}

	static Expressao *extrai_expressao(No_arv_parse *no);
	static No_arv_parse *get_tipo_expressao(No_arv_parse *no);
	virtual void checa_variaveis(bool chamada = false)
	{
		cout << "Não implementado" << endl;
	}

	virtual void carrega_frame(FrameFuncao *frame)
	{
		cout << "Carrega frame não implementado" << endl;
	}

	virtual Valor *calcula_valor(vector<Valor *> &params)
	{
		cout << "Não implementado" << endl;
	}

	virtual void debug()
	{
		cout << "Não implementado" << endl;
	}
};
