#pragma once
#define EXPRESSAO_DECLARACAO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"
#include "Variavel.hpp"

class ExpressaoDeclaracao : public Expressao {
public:
  Variavel *variavel;
  Expressao *expressao;
  ExpressaoDeclaracao(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params);
  void debug() {
    cout << "Expressão de Declaração:" << endl;
    cout << "{" << endl;
    variavel->debug();
    expressao->debug();
    cout << "}" << endl;
  }
};
