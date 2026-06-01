#include "ExpressaoIf.hpp"
#include "Bool.hpp"
#include "Expressao.hpp"
#include "Tipos.hpp"
ExpressaoIf::ExpressaoIf(No_arv_parse *no)
{

	if (no->regra == 41)
	{
		condicao = Expressao::extrai_expressao(no->filhos[1]);
		resultado = Expressao::extrai_expressao(no->filhos[3]);
	}
	if (no->regra == 43)
	{
		condicao = Expressao::extrai_expressao(no->filhos[2]);
		resultado = Expressao::extrai_expressao(no->filhos[4]);
	}

	if (no->filhos.back()->regra == 42)
	{
		continuacao = Expressao::extrai_expressao(no->filhos.back()->filhos.back());
	}

	if (no->filhos.back()->regra == 43)
	{
		continuacao = new ExpressaoIf(no->filhos.back());
	}
}

Valor *ExpressaoIf::calcula_valor(vector<Valor *> &params)
{
	auto val_condicao = condicao->calcula_valor(params);

	if (!val_condicao)
		return nullptr;
	if (val_condicao->tipo == TIPO_ID)
	{
		val_condicao = ((Identificador *)val_condicao)->get_valor();
	}

	if (val_condicao->tipo != TIPO_BOOL)
	{
		cerr << "Tipo inválido, esperado booleano" << endl;
		return nullptr;
	}

	if (((Bool *)val_condicao)->valor)
	{
		return resultado->calcula_valor(params);
	}
	else
	{
		if (continuacao)
		{
			return continuacao->calcula_valor(params);
		}
	}
	return nullptr;
}
void ExpressaoIf::checa_variaveis(bool chamada)
{
	condicao->checa_variaveis(chamada);
	resultado->checa_variaveis(chamada);

	if (continuacao)
	{
		continuacao->checa_variaveis(chamada);
	}
}
void ExpressaoIf::carrega_frame(FrameFuncao *frame)
{
	condicao->carrega_frame(frame);
	resultado->carrega_frame(frame);

	if (continuacao)
		continuacao->carrega_frame(frame);
}
