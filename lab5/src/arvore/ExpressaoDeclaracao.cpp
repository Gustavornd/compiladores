#include "ExpressaoDeclaracao.hpp"
#include "../frame/FrameAcessoNoFrame.hpp"
#include "../frame/FrameAcessoTemp.hpp"
#include "../frame/FrameFuncao.hpp"
#include "../tree/ExpBinop.hpp"
#include "../tree/ExpConst.hpp"
#include "../tree/ExpMem.hpp"
#include "../tree/ExpTemp.hpp"
#include "../tree/ExpTempFramePointer.hpp"
#include "../tree/OperadorSoma.hpp"
#include "../tree/StmMove.hpp"
#include "Tipos.hpp"

ExpressaoDeclaracao::ExpressaoDeclaracao(No_arv_parse *no)
{
	variavel = Variavel::extrai_variavel_declaracao(no);
	expressao = Expressao::extrai_expressao(no->filhos.back());
	Tipos::adiciona_valor_tabela(variavel->nome_variavel->valor,
								 variavel->tipo_variavel ? variavel->tipo_variavel->valor : "", false);
}

Valor *ExpressaoDeclaracao::calcula_valor(vector<Valor *> &params)
{
	auto val = expressao->calcula_valor(params);
	if (!val)
		return nullptr;
	if (val->tipo == TIPO_ID)
	{
		val = ((Identificador *)val)->get_valor();
	}

	// if (val->tipo == TIPO_REF_FLOAT || val->tipo == TIPO_REF_BOOL ||
	//     val->tipo == TIPO_REF_INT) {
	//   val = ((Ref *)val)->valor;
	// }

	if (!variavel->tipo_variavel)
	{
		Identificador *nome_tipo = new Identificador();
		nome_tipo->tipo = TIPO_ID;
		nome_tipo->valor = val->tipo;
		variavel->tipo_variavel = nome_tipo;
	}

	Tipos::adiciona_valor_tabela(variavel->nome_variavel->valor, variavel->tipo_variavel->valor, false);

	return val;
}
void ExpressaoDeclaracao::checa_variaveis(bool chamada)
{
	expressao->checa_variaveis(chamada);
	if (chamada)
	{
		Tipos::tabela[variavel->nome_variavel->valor].usado = true;
	}
}

void ExpressaoDeclaracao::carrega_frame(FrameFuncao *frame)
{
	expressao->carrega_frame(frame);
	auto simbolo = Tipos::recupera_valor_tabela(variavel->nome_variavel->valor);
	if (!simbolo.usado && !simbolo.frame_acesso && !simbolo.parametro)
	{
		FrameAcessoTemp *frame_acesso = new FrameAcessoTemp();
		Tipos::coloca_frame(variavel->nome_variavel->valor, frame_acesso);
		frame->n_pseudo_registradores++;
	}
}

Stm *ExpressaoDeclaracao::cria_stm()
{
	Simbolo simbolo = Tipos::recupera_valor_tabela(variavel->nome_variavel->valor);
	StmMove *stm;
	if (simbolo.usado || simbolo.parametro)
	{
		OperadorSoma *op = new OperadorSoma();

		ExpTempFramePointer *fp = ExpTempFramePointer::gera_Exp_TempFramePointer();

		FrameAcessoNoFrame *frame = (FrameAcessoNoFrame *)simbolo.frame_acesso;

		ExpConst *exp_const = ExpConst::gera_Exp_Const(frame->posicao_no_frame);

		ExpBinop *exp_binop = ExpBinop::gera_Exp_Binop(op, fp, exp_const);

		ExpMem *exp_mem = ExpMem::gera_Exp_Mem(exp_binop);

		stm = StmMove::gera_Stm_Move(exp_mem, expressao->cria_exp());
	}
	else
	{
		FrameAcessoTemp *frame = (FrameAcessoTemp *)simbolo.frame_acesso;
		ExpTemp *exp_temp = ExpTemp::gera_Exp_Temp(frame->id);

		stm = StmMove::gera_Stm_Move(exp_temp, expressao->cria_exp());
	}

	return stm;
}

Exp *ExpressaoDeclaracao::cria_exp()
{
	return nullptr;
}
