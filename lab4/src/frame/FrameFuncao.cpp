#include "FrameFuncao.hpp"
#include "../arvore/Comando.hpp"
#include "../arvore/Tipos.hpp"
FrameFuncao::FrameFuncao()
{
}

FrameFuncao *FrameFuncao::gera_frame_de_funcao(Comando *comando)
{
	FrameFuncao *frame = new FrameFuncao();
	comando->checa_variaveis();
	comando->carrega_frame(frame);
	frame->tamanho_frame += (frame->n_maximo_param_saida * 8);
	return frame;
}

void FrameFuncao::imprime_campos()
{
	cout << "tamanho_frame: " << tamanho_frame << endl;
	cout << "n_param_entrada: " << n_param_entrada << endl;
	cout << "n_maximo_param_saida: " << n_maximo_param_saida << endl;
	cout << "n_pseudo_registradores: " << n_pseudo_registradores << endl;
	cout << "n_variaveis_no_frame: " << n_variaveis_no_frame << endl;

	for (const auto &var : Tipos::tabela)
	{
		cout << "nome_variavel: " << var.first << endl;
		if (!var.second.frame_acesso)
		{
			cout << "parâmetro de entrada" << endl;
		}
		else
		{
			var.second.frame_acesso->imprime();
		}
		cout << endl;
	}
}
