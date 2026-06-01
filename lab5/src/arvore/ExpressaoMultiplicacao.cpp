#include "ExpressaoMultiplicacao.hpp"
#include "../tree/ExpBinop.hpp"
#include "../tree/OperadorMultiplicacao.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Tipos.hpp"
ExpressaoMultiplicacao::ExpressaoMultiplicacao(No_arv_parse *no)
{
	this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
	this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoMultiplicacao::calcula_valor(vector<Valor *> &params)
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
			Int *resultado = new Int();
			resultado->tipo = val1->tipo;
			resultado->valor = ((Int *)val1)->valor * ((Int *)val2)->valor;
			return resultado;
		}
		else if (val1->tipo == TIPO_FLOAT)
		{
			Float *resultado = new Float();
			resultado->tipo = val1->tipo;
			resultado->valor = ((Float *)val1)->valor * ((Float *)val2)->valor;
			return resultado;
		}
		else
		{
			cerr << "Tipos inválidos na Multiplicacao" << endl;
		}
	}
	else
	{
		cerr << "Tipos inválidos na Multiplicacao" << endl;
	}

	return nullptr;
}
void ExpressaoMultiplicacao::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	direita->checa_variaveis(chamada);
}
void ExpressaoMultiplicacao::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	direita->carrega_frame(frame);
}

Exp *ExpressaoMultiplicacao::cria_exp()
{
	OperadorMultiplicacao *op = new OperadorMultiplicacao();
	ExpBinop *binop = ExpBinop::gera_Exp_Binop(op, esquerda->cria_exp(), direita->cria_exp());

	return binop;
}

Stm *ExpressaoMultiplicacao::cria_stm()
{
	return nullptr;
}
