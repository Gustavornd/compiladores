#pragma once
#define INT_HPP
#include "../Arvore.hpp"
#include "Valor.hpp"

class Int : public Valor
{
public:
    int valor;
    
    static Int *extrai_int(No_arv_parse *no);
    void *aloca_valor();
    void debug()
    {
        cout << "Int: " << valor << endl;
    }
};
