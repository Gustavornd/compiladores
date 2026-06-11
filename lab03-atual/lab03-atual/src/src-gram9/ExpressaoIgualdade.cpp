#include "ExpressaoIgualdade.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoIgualdade::ExpressaoIgualdade() { }

void ExpressaoIgualdade::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "== [ INI Igualdade"<< endl;
  esquerda->debug();
  tab3(tab);
  cerr << "==" << endl;
  direita->debug();
  tab3(tab);
  cerr << "== ] FIM Igualdade"<< endl;
}
