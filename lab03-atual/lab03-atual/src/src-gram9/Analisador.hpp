#define ANALISADOR_HPP
#include "Funcao.hpp"
#include "Valor.hpp"
#include "ValorLiteral.hpp"
#include <vector>

class Analisador
{
public:
    // Ajustado para receber o ponteiro de Funcao e o vetor de estruturas literais do arquivo .params
    double calcula_ultimo_valor(Funcao *func, vector<ValorLiteral>& params);
};