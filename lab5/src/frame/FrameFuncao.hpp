#pragma once
#define _FRAME_FUNCAO_HPP_
// #include "../arvore/Comando.hpp"

class Comando;

class FrameFuncao
{
	public:
	int tamanho_frame = 40;
	int n_param_entrada = 0;
	int n_maximo_param_saida = 0;
	int n_pseudo_registradores = 0;
	int n_variaveis_no_frame = 0;

	FrameFuncao();
	void imprime_campos();
	static FrameFuncao *gera_frame_de_funcao(Comando *comando);
};
