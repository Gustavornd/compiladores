#include "Tipos.hpp"
#include <iostream>

map<string, Simbolo> Tipos::tabela;

void Tipos::adiciona_valor_tabela(string id, string tipo, Valor *valor) {
  Tipos::tabela[id] = {tipo, valor->aloca_valor()};
}

Simbolo Tipos::recupera_valor_tabela(string id) {
  if (Tipos::tabela.count(id) == 0) {
    return {"", nullptr};
  }

  return tabela[id];
}
