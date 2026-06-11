#pragma once
#include "Expressao.hpp"

class ExpressaoAcessoArray : public Expressao {
public:
    Expressao *array_expr;
    Expressao *indice_expr;
    ExpressaoAcessoArray(No_arv_parse *no);
    Valor *calcula_valor(vector<Valor *> &params) override;
};