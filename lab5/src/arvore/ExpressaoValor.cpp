#include "ExpressaoValor.hpp"
#include "../frame/FrameAcessoNoFrame.hpp"
#include "../frame/FrameAcessoTemp.hpp"
#include "../frame/FrameFuncao.hpp"
#include "../tree/ExpBinop.hpp"
#include "../tree/ExpConst.hpp"
#include "../tree/ExpMem.hpp"
#include "../tree/ExpTemp.hpp"
#include "../tree/ExpTempFramePointer.hpp"
#include "../tree/OperadorSoma.hpp"

#include "Bool.hpp"
#include "Float.hpp"
#include "Identificador.hpp"
#include "Int.hpp"
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

Exp *ExpressaoValor::cria_exp()
{
	if (valor->tipo == TIPO_ID)
	{
		string nome = ((Identificador *)valor)->valor;
		Simbolo simbolo = Tipos::recupera_valor_tabela(nome);

		if (simbolo.usado || simbolo.parametro)
		{
			FrameAcessoNoFrame *frame = (FrameAcessoNoFrame *)simbolo.frame_acesso;
			OperadorSoma *op = new OperadorSoma();

			ExpTempFramePointer *fp = new ExpTempFramePointer();
			ExpConst *exp_const = ExpConst::gera_Exp_Const(frame->posicao_no_frame);
			ExpBinop *binop = ExpBinop::gera_Exp_Binop(op, fp, exp_const);

			ExpMem *mem = ExpMem::gera_Exp_Mem(binop);

			return mem;
		}
		else if (simbolo.parametro)
		{
		}
		else
		{
			FrameAcessoTemp *frame = (FrameAcessoTemp *)simbolo.frame_acesso;
			ExpTemp *temp = ExpTemp::gera_Exp_Temp(frame->id);

			return temp;
		}
	}

	if (valor->tipo == TIPO_INT)
	{
		Int *v = (Int *)valor;
		int num = v->valor;
		ExpConst *c = ExpConst::gera_Exp_Const(num);
		return c;
	}

	if (valor->tipo == TIPO_BOOL)
	{
		Bool *v = (Bool *)valor;
		int num = v->valor;
		ExpConst *c = ExpConst::gera_Exp_Const(num);
		return c;
	}

	if (valor->tipo == TIPO_FLOAT)
	{
		Float *v = (Float *)valor;
		int num = v->valor;
		ExpConst *c = ExpConst::gera_Exp_Const(num);
		return c;
	}

	return nullptr;
}

Stm *ExpressaoValor::cria_stm()
{
	return nullptr;
}
