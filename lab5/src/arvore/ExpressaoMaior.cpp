#include "ExpressaoMaior.hpp"
#include "../tree/ExpBinop.hpp"
#include "../tree/OperadorMaior.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Tipos.hpp"

ExpressaoMaior::ExpressaoMaior(No_arv_parse *no)
{
	this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
	this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoMaior::calcula_valor(vector<Valor *> &params)
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
		if (val1->tipo == TIPO_INT)
		{
			Bool *resultado = new Bool();
			resultado->tipo = TIPO_BOOL;
			resultado->valor = ((Int *)val1)->valor > ((Int *)val2)->valor;
			return resultado;
		}
		else if (val1->tipo == TIPO_FLOAT)
		{
			Bool *resultado = new Bool();
			resultado->tipo = val1->tipo;
			resultado->valor = ((Float *)val1)->valor > ((Float *)val2)->valor;
			return resultado;
		}
		else
		{
			cerr << "Tipos inválidos no Maior" << endl;
		}
	}
	else
	{
		cerr << "Tipos inválidos no Maior" << endl;
	}

	return nullptr;
}
void ExpressaoMaior::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	direita->checa_variaveis(chamada);
}
void ExpressaoMaior::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	direita->carrega_frame(frame);
}

Exp *ExpressaoMaior::cria_exp()
{
	OperadorMaior *op = new OperadorMaior();
	ExpBinop *binop = ExpBinop::gera_Exp_Binop(op, esquerda->cria_exp(), direita->cria_exp());

	return binop;
}

Stm *ExpressaoMaior::cria_stm()
{
	return nullptr;
}
