#pragma once
#define UNIT_HPP
#include "Valor.hpp"

class Unit : public Valor
{
public:
    Unit() {}
    void *aloca_valor()
    {
        return nullptr;
    }
    void debug()
    {
        cout << "Unit" << endl;
    }
};
