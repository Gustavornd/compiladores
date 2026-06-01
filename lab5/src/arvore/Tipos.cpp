#include "Tipos.hpp"

map<string, Simbolo> Tipos::tabela;

void Tipos::adiciona_valor_tabela(string id, string tipo, bool parametro)
{
	Tipos::tabela[id] = {tipo, false, parametro};
}

Simbolo Tipos::recupera_valor_tabela(string id)
{
	if (Tipos::tabela.count(id) == 0)
	{
		return {""};
	}

	return tabela[id];
}

void Tipos::coloca_frame(string id, FrameAcesso *frame)
{
	Tipos::tabela[id].frame_acesso = frame;
}
