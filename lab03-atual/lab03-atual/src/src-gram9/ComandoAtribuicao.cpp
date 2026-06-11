#include "ComandoAtribuicao.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ComandoAtribuicao::ComandoAtribuicao() {
  
}

void ComandoAtribuicao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "INI ATRIB: " << (esquerda ? esquerda->nome : "NULL") << " = " << endl;
  if (direita) {
      direita->debug();
  }
  tab3(tab);
  cerr << "FIM ATRIB" << endl;
  cerr << endl;
}