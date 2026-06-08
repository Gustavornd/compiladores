#pragma once
#define EXPRESSAO_VALOR_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"
#include "Valor.hpp"
class ExpressaoValor : public Expressao {
public:
  ExpressaoValor(No_arv_parse *no);
  Valor *valor;
  Valor *calcula_valor(vector<Valor *> &params);

  void debug() {
    cout << "Expressão Valor" << endl;
    cout << "{" << endl;
    valor->debug();
    cout << "}" << endl;
  }
};
