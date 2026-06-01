#pragma once
#define EXPRESSAO_IN_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

class ExpressaoIn : public Expressao
{
	public:
	ExpressaoIn(No_arv_parse *no);

	Expressao *esquerda;
	Expressao *direita;
	Valor *calcula_valor(vector<Valor *> &params);
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);

	Stm *cria_stm();
	Exp *cria_exp();

	void debug()
	{
		cout << "Expressão IN:" << endl;
		cout << "{" << endl;
		cout << "Esquerda: " << endl;
		esquerda->debug();
		cout << "Direita: " << endl;
		direita->debug();
		cout << "}" << endl;
	}
};
