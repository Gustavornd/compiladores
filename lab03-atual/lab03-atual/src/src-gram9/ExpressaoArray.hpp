#pragma once
#include "Expressao.hpp"

class ExpressaoArray : public Expressao {
public:
    ExpressaoArray(No_arv_parse *no);
    Valor *calcula_valor(vector<Valor *> &params) override;
};