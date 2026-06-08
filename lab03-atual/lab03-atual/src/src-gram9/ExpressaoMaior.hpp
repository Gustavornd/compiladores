#pragma once
#define EXPRESSAO_MAIOR_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

#include <iostream>

class ExpressaoMaior : public Expressao {
public:
  ExpressaoMaior(No_arv_parse *no);
  Expressao *esquerda;
  Expressao *direita;
  Valor *calcula_valor(vector<Valor *> &params);

  void debug() {
    cout << "Expressão Maior" << endl;
    cout << "{" << endl;

    cout << "Esquerda: " << endl;
    esquerda->debug();
    cout << "Direita: " << endl;
    direita->debug();
    cout << "}" << endl;
  }
};
