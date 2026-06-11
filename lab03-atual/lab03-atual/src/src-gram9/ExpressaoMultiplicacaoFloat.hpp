#pragma once
#include "Expressao.hpp"

class ExpressaoMultiplicacaoFloat : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;
  ExpressaoMultiplicacaoFloat(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params) override;
};