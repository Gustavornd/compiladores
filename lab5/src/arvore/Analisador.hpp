#pragma once
#define ANALISADOR_HPP
#include "Comando.hpp"
#include "Variavel.hpp"
#include "Valor.hpp"
#include <vector>
class Analisador
{
public:
    Valor *calcula_ultimo_valor(Comando *comando, vector<Valor *>& params);
};
