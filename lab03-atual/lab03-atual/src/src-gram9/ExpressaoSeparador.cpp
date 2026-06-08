#include "ExpressaoSeparador.hpp"
#include "Expressao.hpp"

ExpressaoSeparador::ExpressaoSeparador(No_arv_parse *no) {

  esquerda = Expressao::extrai_expressao(no->filhos[0]);

  if (no->filhos[2]->regra == 36) {
    direita = Expressao::extrai_expressao(no->filhos[2]->filhos[0]);
  }
}

Valor *ExpressaoSeparador::calcula_valor(vector<Valor *> &params) {
  esquerda->calcula_valor(params);
  return direita->calcula_valor(params);
}
