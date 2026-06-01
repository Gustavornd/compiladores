#include "ExpressaoOU.hpp"
#include "../tree/ExpBinop.hpp"
#include "../tree/OperadorOU.hpp"
#include "Bool.hpp"
#include "Tipos.hpp"
ExpressaoOU::ExpressaoOU(No_arv_parse *no)
{
	this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
	this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoOU::calcula_valor(vector<Valor *> &params)
{
	auto val1 = esquerda->calcula_valor(params);
	auto val2 = direita->calcula_valor(params);

	if (!val1 || !val2)
		return nullptr;
	if (val1->tipo == TIPO_ID)
	{
		val1 = ((Identificador *)val1)->get_valor();
	}

	if (val2->tipo == TIPO_ID)
	{
		val2 = ((Identificador *)val2)->get_valor();
	}

	if (val1->tipo == val2->tipo)
	{
		if (val1->tipo == TIPO_BOOL)
		{
			Bool *resultado = new Bool();
			resultado->tipo = TIPO_BOOL;
			resultado->valor = ((Bool *)val1)->valor || ((Bool *)val2)->valor;
			return resultado;
		}
		cerr << "Tipos inválidos no OU" << endl;
	}
	else
	{
		cerr << "Tipos inválidos no OU" << endl;
	}

	return nullptr;
}
void ExpressaoOU::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	direita->checa_variaveis(chamada);
}
void ExpressaoOU::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	direita->carrega_frame(frame);
}

Exp *ExpressaoOU::cria_exp()
{
	OperadorOU *op = new OperadorOU();
	ExpBinop *binop = ExpBinop::gera_Exp_Binop(op, esquerda->cria_exp(), direita->cria_exp());

	return binop;
}

Stm *ExpressaoOU::cria_stm()
{
	return nullptr;
}
