#include "ExpressaoChamadaFuncao.hpp"
#include "../frame/FrameFuncao.hpp"
#include "Bool.hpp"
#include "Expressao.hpp"
#include "Identificador.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"
ExpressaoChamadaFuncao::ExpressaoChamadaFuncao(No_arv_parse *no)
{

	nome_funcao = Identificador::extrai_identificador(no->filhos[0]);

	if (no->regra == 87)
	{
		argumentos = ExpressaoChamadaFuncao::extrai_argumentos(no);
	}
}

vector<Expressao *> ExpressaoChamadaFuncao::extrai_argumentos(No_arv_parse *no)
{
	vector<Expressao *> v;
	auto arg = Expressao::extrai_expressao(no->filhos[1]);
	v.push_back(arg);

	if (no->filhos[2]->regra == 88)
	{
		auto atual = no->filhos[2];

		while (atual->regra == 88)
		{
			auto a = Expressao::extrai_expressao(atual->filhos[0]);
			v.push_back(a);
			atual = atual->filhos[1];
		}
	}
	return v;
}

Valor *ExpressaoChamadaFuncao::calcula_valor(vector<Valor *> &params)
{
	if (nome_funcao->valor == "ref")
	{
		if (argumentos.size() != 1)
		{
			cerr << "Número de argumentos em ref inválidos" << endl;
			return nullptr;
		}

		Valor *v = argumentos[0]->calcula_valor(params);
		Ref *ref = new Ref();

		if (v->tipo == TIPO_INT)
		{
			ref->tipo = TIPO_REF_INT;
		}
		else if (v->tipo == TIPO_FLOAT)
		{
			ref->tipo = TIPO_REF_FLOAT;
		}
		else if (v->tipo == TIPO_BOOL)
		{
			ref->tipo = TIPO_REF_BOOL;
		}
		else
		{
			cerr << "Tipo inválido para ref" << endl;
		}

		ref->valor = v;

		return ref;
	}

	if (nome_funcao->valor == "not")
	{
		if (argumentos.size() != 1)
		{
			cerr << "Número de argumentos em ref inválidos" << endl;
			return nullptr;
		}
		Valor *v = argumentos[0]->calcula_valor(params);
		if (v->tipo == TIPO_ID)
		{
			v = ((Identificador *)v)->get_valor();
		}

		if (v->tipo != TIPO_BOOL)
		{
			cerr << "Tipo inválido para not" << endl;
			return nullptr;
		}

		Bool *not_bool;
		not_bool->tipo = TIPO_BOOL;
		not_bool->valor = !((Bool *)v)->valor;

		return not_bool;
	}

	return nullptr;
}

void ExpressaoChamadaFuncao::checa_variaveis(bool chamada)
{
	for (int i = 0; i < argumentos.size(); i++)
	{
		argumentos[i]->checa_variaveis(true);
	}
}

void ExpressaoChamadaFuncao::carrega_frame(FrameFuncao *frame)
{
	for (int i = 0; i < argumentos.size(); i++)
	{
		argumentos[i]->carrega_frame(frame);
	}
	if (argumentos.size() > frame->n_maximo_param_saida)
	{
		frame->n_maximo_param_saida = argumentos.size();
	}
}
