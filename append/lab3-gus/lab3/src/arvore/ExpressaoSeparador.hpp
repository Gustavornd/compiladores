#pragma once
#define EXPRESSAO_SEPARADOR_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"

class ExpressaoSeparador : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;

  ExpressaoSeparador(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params);

  void debug() {
    cout << "Expressão Separador" << endl;
    cout << "{" << endl;
    cout << "Esquerda: " << endl;
    esquerda->debug();
    cout << "Direita: " << endl;
    direita->debug();
    cout << "}" << endl;
  }
};
