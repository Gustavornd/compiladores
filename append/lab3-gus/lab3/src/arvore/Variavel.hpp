#pragma once
#define VARIAVEL_HPP
#include "Identificador.hpp"
#include <vector>
#include <iostream>
class Variavel
{
public:
    Identificador *nome_variavel;
    Identificador *tipo_variavel;

    static vector<Variavel *> extrai_parametros(No_arv_parse *no);
    static vector<Variavel *> extrai_params_recursivo(No_arv_parse *no);
    static Variavel *extrai_variavel_declaracao(No_arv_parse *no);

    void debug()
    {
        cout << "Variável: " << nome_variavel->valor << " ;; " << (tipo_variavel ? tipo_variavel->valor : "") << endl;
    }
};
