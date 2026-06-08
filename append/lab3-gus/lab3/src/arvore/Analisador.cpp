#include "Analisador.hpp"

Valor *Analisador::calcula_ultimo_valor(Comando *comando, vector<Valor *>& params)
{
    return comando->calcula_valor(params);
}
