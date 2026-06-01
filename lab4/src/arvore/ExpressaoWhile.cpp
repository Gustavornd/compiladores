#include "ExpressaoWhile.hpp"
#include "Bool.hpp"
#include "Expressao.hpp"
#include "Tipos.hpp"

ExpressaoWhile::ExpressaoWhile(No_arv_parse *no)
{
	condicao = Expressao::extrai_expressao(no->filhos[1]);
	resultado = Expressao::extrai_expressao(no->filhos[3]);
}
Valor *ExpressaoWhile::calcula_valor(vector<Valor *> &params)
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
	Valor *val_resultado;
	while (((Bool *)val_condicao)->valor == true)
	{
		val_resultado = resultado->calcula_valor(params);
		val_condicao = condicao->calcula_valor(params);
		if (val_condicao->tipo == TIPO_ID)
		{
			val_condicao = ((Identificador *)val_condicao)->get_valor();
		}
	}
	return val_resultado;
}

void ExpressaoWhile::checa_variaveis(bool chamada)
{
	condicao->checa_variaveis(chamada);
	resultado->checa_variaveis(chamada);
}
void ExpressaoWhile::carrega_frame(FrameFuncao *frame)
{
	condicao->carrega_frame(frame);
	resultado->carrega_frame(frame);
}
