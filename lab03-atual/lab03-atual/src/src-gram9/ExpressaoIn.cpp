#include "ExpressaoIn.hpp"
#include "Tipos.hpp"
ExpressaoIn::ExpressaoIn(No_arv_parse *no) {
  esquerda = Expressao::extrai_expressao(no->filhos[0]);
  direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoIn::calcula_valor(vector<Valor *> &params) {
  auto exp1 = esquerda->calcula_valor(params);
  if (!exp1) {
    return nullptr;
  }
  auto exp2 = direita->calcula_valor(params);
  if (!exp2) {
    return nullptr;
  }
  if (exp2->tipo != TIPO_UNIT)
    return exp2;
  return exp1;
}
