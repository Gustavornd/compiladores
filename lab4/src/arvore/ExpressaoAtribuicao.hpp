#pragma once
#define EXPRESSAO_ATRIBUICAO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

class ExpressaoAtribuicao : public Expressao
{
	public:
	ExpressaoAtribuicao(No_arv_parse *no);
	Valor *calcula_valor(vector<Valor *> &params);
	Expressao *esquerda;
	Expressao *direita;
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);

	void debug()
	{
		cout << "Expressão Atribuicao" << endl;
		cout << "{" << endl;
		cout << "Esquerda" << endl;
		esquerda->debug();
		cout << "Direita" << endl;
		direita->debug();
		cout << "}" << endl;
	}
};
