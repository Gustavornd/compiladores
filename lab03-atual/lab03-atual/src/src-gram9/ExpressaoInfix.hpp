#pragma once
#include "Expressao.hpp"
#include <string>

class ExpressaoInfix : public Expressao {
public:
  Expressao *esquerda;
  Expressao *direita;
  std::string simbolo;
  ExpressaoInfix(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params) override;
};