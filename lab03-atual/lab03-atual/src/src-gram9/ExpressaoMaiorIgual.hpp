#pragma once
#include "Expressao.hpp"

class ExpressaoMaiorIgual : public Expressao{
    public:
        Expressao *esquerda;
        Expressao *direita;
        ExpressaoMaiorIgual(No_arv_parse *no);
        Valor *calcula_valor(vector<Valor *> &params) override;

};