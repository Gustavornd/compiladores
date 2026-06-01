#pragma once
#define EXPRESSAO_MENOR_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

#include <iostream>

class ExpressaoMenor : public Expressao
{
	public:
	ExpressaoMenor(No_arv_parse *no);
	Expressao *esquerda;
	Expressao *direita;
	Valor *calcula_valor(vector<Valor *> &params);
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);

	void debug()
	{
		cout << "Expressão Maior" << endl;
		cout << "{" << endl;

		cout << "Esquerda: " << endl;
		esquerda->debug();
		cout << "Direita: " << endl;
		direita->debug();
		cout << "}" << endl;
	}
};
