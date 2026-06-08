#pragma once
#define COMANDO_HPP

#include "../Arvore.hpp"
#include "Expressao.hpp"
class Comando {
public:
  Comando() {}
  ~Comando() {}

  Expressao *expressao;

  static Comando *extrai_comando(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params);
  void debug() { expressao->debug(); }
};
