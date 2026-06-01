#pragma once
#define FLOAT_HPP
#include "../Arvore.hpp"
#include "Valor.hpp"
class Bool : public Valor
{
public:
    bool valor;

    static Bool *extrai_bool(No_arv_parse *no);
    void * aloca_valor();
    void debug()
    {
        cout << "Bool: " << (valor ? "true" : "false") << endl;
    }
};
