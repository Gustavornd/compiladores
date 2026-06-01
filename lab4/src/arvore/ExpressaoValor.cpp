#include "ExpressaoValor.hpp"
#include "../frame/FrameAcessoNoFrame.hpp"
#include "../frame/FrameFuncao.hpp"
#include "Identificador.hpp"
#include "Tipos.hpp"
#include "Valor.hpp"
ExpressaoValor::ExpressaoValor(No_arv_parse *no)
{
	this->valor = Valor::extrai_valor(no);
}

Valor *ExpressaoValor::calcula_valor(vector<Valor *> &params)
{
	// if (valor->tipo == TIPO_ID) {
	//   return ((Identificador *)valor)->get_valor();
	// }

	return valor;
}
void ExpressaoValor::checa_variaveis(bool chamada)
{
	if (valor->tipo == TIPO_ID)
	{
		if (chamada)
		{
			Tipos::tabela[((Identificador *)valor)->valor].usado = true;
		}
	}
}
void ExpressaoValor::carrega_frame(FrameFuncao *frame)
{
	if (valor->tipo == TIPO_ID)
	{
		string nome = ((Identificador *)valor)->valor;
		auto simbolo = Tipos::recupera_valor_tabela(nome);

		if (simbolo.usado && !simbolo.frame_acesso && !simbolo.parametro)
		{
			FrameAcessoNoFrame *frame_acesso = new FrameAcessoNoFrame();
			Tipos::coloca_frame(nome, frame_acesso);
			frame->n_variaveis_no_frame++;
			frame->tamanho_frame += 8;
		}
	}
}
