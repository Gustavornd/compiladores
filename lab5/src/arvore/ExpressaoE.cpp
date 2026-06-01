#include "ExpressaoE.hpp"
#include "../tree/ExpBinop.hpp"
#include "../tree/OperadorE.hpp"
#include "Bool.hpp"
#include "Tipos.hpp"
ExpressaoE::ExpressaoE(No_arv_parse *no)
{
	this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
	this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoE::calcula_valor(vector<Valor *> &params)
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
			resultado->valor = ((Bool *)val1)->valor && ((Bool *)val2)->valor;
			return resultado;
		}
		cerr << "Tipos inválidos no E-logico" << endl;
	}
	else
	{
		cerr << "Tipos inválidos no E-logico" << endl;
	}

	return nullptr;
}
void ExpressaoE::checa_variaveis(bool chamada)
{
	esquerda->checa_variaveis(chamada);
	direita->checa_variaveis(chamada);
}
void ExpressaoE::carrega_frame(FrameFuncao *frame)
{
	esquerda->carrega_frame(frame);
	direita->carrega_frame(frame);
}
Exp *ExpressaoE::cria_exp()
{
	OperadorE *op = new OperadorE();

	ExpBinop *binop = ExpBinop::gera_Exp_Binop(op, esquerda->cria_exp(), direita->cria_exp());
	return binop;
}

Stm *ExpressaoE::cria_stm()
{
	return nullptr;
}
