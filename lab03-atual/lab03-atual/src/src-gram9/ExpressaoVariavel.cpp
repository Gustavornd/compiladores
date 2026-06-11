#include "ExpressaoVariavel.hpp"
#include "Identificador.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;
// Implementação do construtor que aceita o nó da árvore
ExpressaoVariavel::ExpressaoVariavel(No_arv_parse *no) {
    this->nome = Identificador::extrai_identificador(no);
}

void ExpressaoVariavel::debug_com_tab(int tab) {
  tab3(tab);
  // Acessando .valor que é a string do identificador
  cerr << "VAR[" << (nome ? nome->valor : "NULL") << "]" << endl;
}
