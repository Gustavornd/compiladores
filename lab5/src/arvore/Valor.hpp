#pragma once
#define VALOR_HPP
#include "../Arvore.hpp"
#include <iostream>
class Valor
{
public:
    static Valor *extrai_valor(No_arv_parse *no);
    string tipo;
    virtual void *aloca_valor()
    {
        cerr << "Alocação não implementada" << endl;
        return nullptr;
    }
    virtual void debug()
    {
        cout << "VALOR COM DEBUG NÃO IMPLEMENTADO" << endl;
    }
};
