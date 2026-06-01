#include "ExpressaoAtribuicao.hpp"
#include "../tree/StmMove.hpp"
#include "Expressao.hpp"
#include "Identificador.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"

ExpressaoAtribuicao::ExpressaoAtribuicao(No_arv_parse *no)
{
	esquerda = Expressao::extrai_expressao(no->filhos[0]);
	direita = Expressao::extrai_expressao(no->filhos[2]);
}
Valor *ExpressaoAtribuicao::calcula_valor(vector<Valor *> &params)
{
	auto val_esq = esquerda->calcula_valor(params);
	auto val_dir = direita->calcula_valor(params);
	if (!val_esq || !val_dir)
		return nullptr;

	if (val_esq->tipo != TIPO_ID)
	{
		cerr << "Tipo invalido em atribuicao" << endl;
	}
	auto val = ((Identificador *)val_esq)->get_valor();

	if (val->tipo != TIPO_REF_FLOAT && val->tipo != TIPO_REF_BOOL && val->tipo != TIPO_REF_INT)
	{
		cerr << "Tipo inválido em atribuiçao" << endl;
		return nullptr;
	}

	if (val_dir->tipo == TIPO_ID)
	{
		val_dir = ((Identificador *)val_dir)->get_valor();
	}

	if (((Ref *)val)->valor->tipo == val_dir->tipo)
	{
		auto id = ((Identificador *)val_esq)->valor;
		Tipos::adiciona_valor_tabela(id, val->tipo);
	}

	return val_esq;
}

void ExpressaoAtribuicao::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	direita->checa_variaveis(chamada);
}

void ExpressaoAtribuicao::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	direita->carrega_frame(frame);
}

Stm *ExpressaoAtribuicao::cria_stm()
{
	StmMove *move = StmMove::gera_Stm_Move(esquerda->cria_exp(), direita->cria_exp());

	return move;
}

Exp *ExpressaoAtribuicao::cria_exp()
{
	return nullptr;
}
