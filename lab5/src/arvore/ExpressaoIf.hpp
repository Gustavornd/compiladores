#pragma once
#include "Expressao.hpp"
#define EXPRESSAO_IF_HPP

class ExpressaoIf : public Expressao
{
	public:
	ExpressaoIf(No_arv_parse *no);

	static int label_counter;
	Expressao *condicao;
	Expressao *resultado;
	Expressao *continuacao;
	Valor *calcula_valor(vector<Valor *> &params);

	void checa_variaveis(bool chamada = false);
	void carrega_frame(FrameFuncao *frame);
	Stm *cria_stm();
	Exp *cria_exp();

	void debug()
	{
		cout << "Expressão IF" << endl;
		cout << "{" << endl;
		condicao->debug();
		continuacao->debug();
		cout << "}" << endl;
	}
};
