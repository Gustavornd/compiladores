#pragma once
#include "Expressao.hpp"

class ExpressaoMenorIgual : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;
  ExpressaoMenorIgual(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params) override;
};