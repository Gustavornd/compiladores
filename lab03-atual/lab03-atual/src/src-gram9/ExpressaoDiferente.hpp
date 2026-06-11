#pragma once
#include "Expressao.hpp"

class ExpressaoDiferente : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;
  ExpressaoDiferente(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params) override;
};