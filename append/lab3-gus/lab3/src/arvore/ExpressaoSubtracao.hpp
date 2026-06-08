#pragma once
#define EXPRESSA_SUBTRACAO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"
class ExpressaoSubtracao : public Expressao {
public:
  ExpressaoSubtracao(No_arv_parse *no);
  Expressao *esquerda;
  Expressao *direita;
  Valor *calcula_valor(vector<Valor *> &params);
  void debug() {
    cout << "Expressao de Subtracao" << endl;

    cout << "{" << endl;
    cout << "Esquerda:" << endl;
    esquerda->debug();
    cout << "Direita: " << endl;
    direita->debug();
    cout << "}" << endl;
  }
};
