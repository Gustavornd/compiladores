#pragma once
#include "Expressao.hpp"

class ExpressaoSubtracaoFloat : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;
  ExpressaoSubtracaoFloat(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params) override;
};