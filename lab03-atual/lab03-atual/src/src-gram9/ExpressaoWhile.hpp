#pragma once
#include "Expressao.hpp"
#define EXPRESSAO_IF_HPP

class ExpressaoWhile : public Expressao {
public:
  ExpressaoWhile(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params);
  Expressao *condicao;
  Expressao *resultado;

  void debug() {
    cout << "Expressão While" << endl;
    cout << "}" << endl;
    condicao->debug();
    resultado->debug();
    cout << "}" << endl;
  }
};
