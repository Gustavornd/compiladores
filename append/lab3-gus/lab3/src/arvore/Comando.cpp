#include "Comando.hpp"
#include <iostream>
using namespace std;

Comando *Comando::extrai_comando(No_arv_parse *no)
{
    Comando *comando = new Comando();
    comando->expressao = Expressao::extrai_expressao(no->filhos[0]);
    // comando->debug();

    return comando;
}

Valor *Comando::calcula_valor(vector<Valor *> &params)
{
    return expressao->calcula_valor(params);
}
