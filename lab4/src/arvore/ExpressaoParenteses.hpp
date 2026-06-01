#pragma once
#define EXPRESSAO_PARENTESES_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

class ExpressaoParenteses : public Expressao
{
	public:
	ExpressaoParenteses(No_arv_parse *no);
	Expressao *expressao;
	Valor *calcula_valor(vector<Valor *> &params);
	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);

	void debug()
	{
		cout << "Expressão de Parenteses" << endl;
		cout << "{" << endl;
		expressao->debug();
		cout << "}" << endl;
	}
};
