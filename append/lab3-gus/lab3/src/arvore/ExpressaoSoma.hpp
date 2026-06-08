#pragma once
#define EXPRESSAO_SOMA_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

class ExpressaoSoma : public Expressao {
public:
  ExpressaoSoma(No_arv_parse *no);
  Expressao *esquerda;
  Expressao *direita;
  Valor *calcula_valor(vector<Valor *> &params);
  void debug() {
    cout << "Expressão de Soma" << endl;
    cout << "Esquerda" << endl;
    cout << "{" << endl;
    esquerda->debug();
    cout << "Direita: " << endl;
    cout << "}" << endl;
    direita->debug();
  }
};
