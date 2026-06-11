#include "Analisador.hpp"
#include <iostream>

double Analisador::calcula_ultimo_valor(Funcao *func, vector<ValorLiteral>& params)
{
    if (func == NULL || func->corpo == NULL) {
        cerr << "Erro: Função ou corpo não definidos para análise." << endl;
        return 0.0;
    }

    // Cria o vetor de objetos Valor* que o interpretador espera receber
    vector<Valor*> parametros_simulacao;
    
    // Mapeia os ValorLiteral fornecidos no sol.cpp para a hierarquia dinâmica de Valor*
    for (auto& p : params) {
        // Exemplo de instanciação de acordo com as classes do seu compilador:
        // Valor* v = new Valor(p.tipo, ...);
        // parametros_simulacao.push_back(v);
    }

    // Simula a execução avaliando recursivamente a árvore de expressões
    Valor* resultado_final = func->corpo->calcula_valor(parametros_simulacao);

    if (resultado_final != NULL) {
        // Dependendo de como a sua classe Valor armazena os dados internos, 
        // extraia o valor numérico correspondente (ex: resultado_final->obter_double())
        return 1.0; // Substitua pelo retorno do valor real calculado
    }

    return 0.0;
}