#include "ExpressaoFuncao.hpp"
#include "../frame/FrameFuncao.hpp"
#include "Identificador.hpp"
#include "Tipos.hpp"
#include <cmath>
#include <execution>

ExpressaoFuncao::ExpressaoFuncao(No_arv_parse *no)
{
	this->nome_funcao = Identificador::extrai_identificador(no->filhos[0]->filhos[1]);
	if (no->regra == 19)
	{
		this->tipo_retorno = Identificador::extrai_identificador(no->filhos[0]->filhos[4]);
	}

	this->parametros = Variavel::extrai_parametros(no->filhos[0]);
	for (auto &v : parametros)
	{
		Tipos::adiciona_valor_tabela(v->nome_variavel->valor, v->tipo_variavel ? v->tipo_variavel->valor : "", true);
	}
	this->expressao = Expressao::extrai_expressao(no->filhos[0]->filhos.back());
}

Valor *ExpressaoFuncao::calcula_valor(vector<Valor *> &params)
{
	if (params.size() < parametros.size())
	{
		cerr << "Parâmetros insuficientes" << endl;
		return nullptr;
	}

	for (int i = 0; i < parametros.size(); i++)
	{
		if (parametros[i]->tipo_variavel)
		{
			if (parametros[i]->tipo_variavel->valor != params[i]->tipo)
			{
				cerr << "Tipos de parâmetros incorretos" << endl;
				return nullptr;
			}
		}
		else
		{
			if (!params[i]->tipo.empty())
			{
				auto tipo = new Identificador();
				tipo->tipo = TIPO_ID;
				tipo->valor = params[i]->tipo;

				parametros[i]->tipo_variavel = tipo;
			}
		}
		Tipos::adiciona_valor_tabela(parametros[i]->nome_variavel->valor, parametros[i]->tipo_variavel->valor);
	}

	return expressao->calcula_valor(params);
}
void ExpressaoFuncao::checa_variaveis(bool chamada)
{
	expressao->checa_variaveis(chamada);
}

void ExpressaoFuncao::carrega_frame(FrameFuncao *frame)
{
	frame->n_param_entrada = parametros.size();
	expressao->carrega_frame(frame);
}
