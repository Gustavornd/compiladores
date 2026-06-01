#pragma once
#define EXPRESSAO_OU_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

#include <iostream>

class ExpressaoOU : public Expressao
{
	public:
	ExpressaoOU(No_arv_parse *no);
	Expressao *esquerda;
	Expressao *direita;
	Valor *calcula_valor(vector<Valor *> &params);
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);
	Stm *cria_stm();
	Exp *cria_exp();

	void debug()
	{
		cout << "Expressão OU" << endl;
		cout << "{" << endl;

		cout << "Esquerda: " << endl;
		esquerda->debug();
		cout << "Direita: " << endl;
		direita->debug();

		cout << "}" << endl;
	}
};
