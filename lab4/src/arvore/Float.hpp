#pragma once
#define FLOAT_HPP
#include "../Arvore.hpp"
#include "Valor.hpp"
class Float : public Valor
{
public:
    float valor;

    static Float *extrai_float(No_arv_parse *no);
    void * aloca_valor();
    void debug()
    {
        cout << "Float: " << valor << endl;
    }
};
