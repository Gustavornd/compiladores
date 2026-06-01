#pragma once
#define EXPRESSAO_PREFIXO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

class ExpressaoPrefixo : public Expressao
{
	public:
	ExpressaoPrefixo(No_arv_parse *no);
	Valor *calcula_valor(vector<Valor *> &params);

	string operador;
	Expressao *expressao;
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);

	void debug()
	{
		cout << "Expressão Prefixo" << endl;
		cout << "{" << endl;
		expressao->debug();
		cout << "}" << endl;
	}
};
