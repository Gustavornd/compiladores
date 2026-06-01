#include "ExpressaoIf.hpp"
#include "../tree/ExpName.hpp"
#include "../tree/StmCJump.hpp"
#include "../tree/StmJump.hpp"
#include "../tree/StmLabel.hpp"
#include "../tree/StmSeq.hpp"
#include "Bool.hpp"
#include "Expressao.hpp"
#include "Tipos.hpp"
#include <string>

int ExpressaoIf::label_counter = 0;

ExpressaoIf::ExpressaoIf(No_arv_parse *no)
{

	if (no->regra == 41)
	{
		condicao = Expressao::extrai_expressao(no->filhos[1]);
		resultado = Expressao::extrai_expressao(no->filhos[3]);
	}
	if (no->regra == 43)
	{
		condicao = Expressao::extrai_expressao(no->filhos[2]);
		resultado = Expressao::extrai_expressao(no->filhos[4]);
	}

	if (no->filhos.back()->regra == 42)
	{
		continuacao = Expressao::extrai_expressao(no->filhos.back()->filhos.back());
	}

	if (no->filhos.back()->regra == 43)
	{
		continuacao = new ExpressaoIf(no->filhos.back());
	}
}

Valor *ExpressaoIf::calcula_valor(vector<Valor *> &params)
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

	if (((Bool *)val_condicao)->valor)
	{
		return resultado->calcula_valor(params);
	}
	else
	{
		if (continuacao)
		{
			return continuacao->calcula_valor(params);
		}
	}
	return nullptr;
}
void ExpressaoIf::checa_variaveis(bool chamada)
{
	condicao->checa_variaveis(chamada);
	resultado->checa_variaveis(chamada);

	if (continuacao)
	{
		continuacao->checa_variaveis(chamada);
	}
}
void ExpressaoIf::carrega_frame(FrameFuncao *frame)
{
	condicao->carrega_frame(frame);
	resultado->carrega_frame(frame);

	if (continuacao)
		continuacao->carrega_frame(frame);
}

Stm *ExpressaoIf::cria_stm()
{
	StmLabel *lbl_true = StmLabel::gera_Stm_Label("Label_" + std::to_string(ExpressaoIf::label_counter++));
	StmLabel *lbl_false = StmLabel::gera_Stm_Label("Label_" + std::to_string(ExpressaoIf::label_counter++));
	StmLabel *lbl_done = StmLabel::gera_Stm_Label("Label_" + std::to_string(ExpressaoIf::label_counter++));
	StmCJump *cjump = StmCJump::gera_Stm_CJump(condicao->cria_exp(), lbl_true->nome, lbl_false->nome);
	StmSeq *seq;
	if (continuacao)
	{
		StmSeq *seq2 = StmSeq::gera_Stm_Seq(continuacao->cria_stm(), lbl_done);
		StmSeq *seq3 = StmSeq::gera_Stm_Seq(lbl_false, seq2);

		ExpName *name_lbl_done = ExpName::gera_Exp_Name(lbl_done->nome);
		StmJump *jmp = StmJump::gera_Stm_Jump(name_lbl_done, {lbl_done->nome});

		StmSeq *seq4 = StmSeq::gera_Stm_Seq(jmp, seq3);
		StmSeq *seq5 = StmSeq::gera_Stm_Seq(resultado->cria_stm(), seq4);
		StmSeq *seq6 = StmSeq::gera_Stm_Seq(lbl_true, seq5);

		seq = StmSeq::gera_Stm_Seq(cjump, seq6);
	}
	else
	{
		StmSeq *seq2 = StmSeq::gera_Stm_Seq(resultado->cria_stm(), lbl_done);
		StmSeq *seq3 = StmSeq::gera_Stm_Seq(lbl_true, seq2);

		seq = StmSeq::gera_Stm_Seq(cjump, seq3);
	}

	return seq;
}

Exp *ExpressaoIf::cria_exp()
{
	return nullptr;
}
