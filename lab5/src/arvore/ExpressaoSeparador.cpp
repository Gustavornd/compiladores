#include "ExpressaoSeparador.hpp"
#include "../tree/StmSeq.hpp"
#include "Expressao.hpp"

ExpressaoSeparador::ExpressaoSeparador(No_arv_parse *no)
{

	esquerda = Expressao::extrai_expressao(no->filhos[0]);

	if (no->filhos[2]->regra == 36)
	{
		direita = Expressao::extrai_expressao(no->filhos[2]->filhos[0]);
	}
}

Valor *ExpressaoSeparador::calcula_valor(vector<Valor *> &params)
{
	esquerda->calcula_valor(params);
	return direita->calcula_valor(params);
}
void ExpressaoSeparador::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	if (direita)
		direita->checa_variaveis(chamada);
}
void ExpressaoSeparador::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	if (direita)
		direita->carrega_frame(frame);
}

Stm *ExpressaoSeparador::cria_stm()
{
	StmSeq *seq = StmSeq::gera_Stm_Seq(esquerda->cria_stm(), direita->cria_stm());

	return seq;
}

Exp *ExpressaoSeparador::cria_exp()
{
	return nullptr;
}
