#pragma once
#include "Expressao.hpp"
#define COMANDO_HPP

#include "../Arvore.hpp"

class FrameFuncao;
class Stm;

class Comando
{
	public:
	Comando()
	{
	}
	~Comando()
	{
	}

	Expressao *expressao;

	static Comando *extrai_comando(No_arv_parse *no);
	Valor *calcula_valor(vector<Valor *> &params);
	void checa_variaveis();
	void carrega_frame(FrameFuncao *frame);
	Stm *cria_ri(FrameFuncao *frame);
	void debug()
	{
		expressao->debug();
	}
};
