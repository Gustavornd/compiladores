#pragma once
#define EXPRESSAO_IGUAL_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

#include <iostream>

class ExpressaoIgual : public Expressao {
public:
  ExpressaoIgual(No_arv_parse *no);
  Expressao *esquerda;
  Expressao *direita;
  Valor *calcula_valor(vector<Valor *> &params);

  void debug() {
    cout << "Expressão Igual" << endl;
    cout << "{" << endl;

    cout << "Esquerda: " << endl;
    esquerda->debug();
    cout << "Direita: " << endl;
    direita->debug();
    cout << "}" << endl;
  }
};
