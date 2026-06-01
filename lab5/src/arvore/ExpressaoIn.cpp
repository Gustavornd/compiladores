#include "ExpressaoIn.hpp"
#include "../tree/StmSeq.hpp"
#include "Tipos.hpp"
ExpressaoIn::ExpressaoIn(No_arv_parse *no)
{
	esquerda = Expressao::extrai_expressao(no->filhos[0]);
	direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoIn::calcula_valor(vector<Valor *> &params)
{
	auto exp1 = esquerda->calcula_valor(params);
	if (!exp1)
	{
		return nullptr;
	}
	auto exp2 = direita->calcula_valor(params);
	if (!exp2)
	{
		return nullptr;
	}
	if (exp2->tipo != TIPO_UNIT)
		return exp2;
	return exp1;
}
void ExpressaoIn::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	direita->checa_variaveis(chamada);
}
void ExpressaoIn::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	direita->carrega_frame(frame);
}

Stm *ExpressaoIn::cria_stm()
{
	StmSeq *seq = StmSeq::gera_Stm_Seq(esquerda->cria_stm(), direita->cria_stm());

	return seq;
}

Exp *ExpressaoIn::cria_exp()
{
	return nullptr;
}
