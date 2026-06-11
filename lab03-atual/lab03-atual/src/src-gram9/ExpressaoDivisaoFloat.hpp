#pragma once
#include "Expressao.hpp"

class ExpressaoDivisaoFloat : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;
  ExpressaoDivisaoFloat(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params) override;
};