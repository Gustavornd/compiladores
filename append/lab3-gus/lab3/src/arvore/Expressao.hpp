#pragma once
#define EXPRESAO_HPP
#include "../Arvore.hpp"
#include "Variavel.hpp"
#include <iostream>
using namespace std;
class Expressao
{
public:
    Expressao() {}
    ~Expressao() {}

    static Expressao *extrai_expressao(No_arv_parse *no);
    static No_arv_parse *get_tipo_expressao(No_arv_parse *no);

    virtual Valor *calcula_valor(vector<Valor *> &params) { cout << "Não implementado" << endl; }

    virtual void debug()
    {
        cout << "Não implementado" << endl;
    }
};
