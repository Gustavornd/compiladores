#pragma once
#include "Expressao.hpp"

class ExpressaoSetae : public Expressao {
public:
    Expressao *esquerda;
    Expressao *direita;
    ExpressaoSetae(No_arv_parse *no);
    Valor *calcula_valor(vector<Valor *> &params) override;
};