#include "Identificador.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"
#include <iostream>
Identificador *Identificador::extrai_identificador(No_arv_parse *no)
{
	Identificador *identificador = new Identificador();
	identificador->valor = no->dado_extra;

	return identificador;
}

void Identificador::une_identificadores(Identificador *id)
{
	valor = valor + " " + id->valor;
}

void *Identificador::aloca_valor()
{
	return nullptr;
}

Valor *Identificador::get_valor()
{
	auto val = Tipos::recupera_valor_tabela(valor);
	return nullptr;
}
