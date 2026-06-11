#include "ComandoDeclaracao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

void ComandoDeclaracao::debug_com_tab(int tab) {
    tab3(tab);
    
    // Pega os valores atualizados da classe Variavel com checagem de nulos
    string n = (variavel->nome_variavel != NULL) ? variavel->nome_variavel->valor : "NULL";
    string t = (variavel->tipo_variavel != NULL) ? variavel->tipo_variavel->valor : "TIPO_INVALIDO";
    
    cerr << "[" << n << ":" << t << "] Declaracao" << endl;
}