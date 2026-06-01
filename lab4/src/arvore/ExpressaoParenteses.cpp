#include "ExpressaoParenteses.hpp"

ExpressaoParenteses::ExpressaoParenteses(No_arv_parse *no)
{
	expressao = Expressao::extrai_expressao(no->filhos[1]);
}

Valor *ExpressaoParenteses::calcula_valor(vector<Valor *> &params)
{

	return expressao->calcula_valor(params);
}
void ExpressaoParenteses::checa_variaveis(bool chamada)
{
	expressao->checa_variaveis(chamada);
}
void ExpressaoParenteses::carrega_frame(FrameFuncao *frame)
{
	expressao->carrega_frame(frame);
}
