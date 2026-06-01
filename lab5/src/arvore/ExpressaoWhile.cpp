#include "ExpressaoWhile.hpp"
#include "../tree/ExpName.hpp"
#include "../tree/StmCJump.hpp"
#include "../tree/StmJump.hpp"
#include "../tree/StmLabel.hpp"
#include "../tree/StmSeq.hpp"

#include "Bool.hpp"
#include "Expressao.hpp"
#include "ExpressaoIf.hpp"
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

Stm *ExpressaoWhile::cria_stm()
{
	StmLabel *label_done = StmLabel::gera_Stm_Label("Label_" + std::to_string(ExpressaoIf::label_counter++));
	StmLabel *label_while = StmLabel::gera_Stm_Label("Label_" + std::to_string(ExpressaoIf::label_counter++));
	StmLabel *label_true = StmLabel::gera_Stm_Label("Label_" + std::to_string(ExpressaoIf::label_counter++));
	ExpName *name_while = ExpName::gera_Exp_Name(label_while->nome);
	StmJump *jump = StmJump::gera_Stm_Jump(name_while, {label_while->nome});
	StmCJump *cjump = StmCJump::gera_Stm_CJump(condicao->cria_exp(), label_true->nome, label_done->nome);

	StmSeq *seq1 = StmSeq::gera_Stm_Seq(label_done, jump);
	StmSeq *seq2 = StmSeq::gera_Stm_Seq(resultado->cria_stm(), seq1);
	StmSeq *seq3 = StmSeq::gera_Stm_Seq(label_true, seq2);
	StmSeq *seq4 = StmSeq::gera_Stm_Seq(cjump, seq3);

	StmSeq *seq = StmSeq::gera_Stm_Seq(label_while, seq4);

	return seq;
}

Exp *ExpressaoWhile::cria_exp()
{
	return nullptr;
}
