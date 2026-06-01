#pragma once
#define EXPRESSAO_DECLARACAO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"
#include "Variavel.hpp"

class ExpressaoDeclaracao : public Expressao
{
	public:
	Variavel *variavel;
	Expressao *expressao;
	ExpressaoDeclaracao(No_arv_parse *no);
	Valor *calcula_valor(vector<Valor *> &params);
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);

	Stm *cria_stm();
	Exp *cria_exp();

	void debug()
	{
		cout << "Expressão de Declaração:" << endl;
		cout << "{" << endl;
		variavel->debug();
		expressao->debug();
		cout << "}" << endl;
	}
};
