#pragma once
#define IDENTIFICADOR_HPP
#include "../Arvore.hpp"
#include "Valor.hpp"
#include <string>
using namespace std;

class Identificador : public Valor {
public:
  string valor;
  static Identificador *extrai_identificador(No_arv_parse *no);
  void une_identificadores(Identificador *id);
  void *aloca_valor();
  Valor *get_valor();

  void debug() {
    cout << "Identificador: " << valor << endl;

    auto v = get_valor();

    if (v) {
      cout << "Valor: " << endl;
      v->debug();
    }
  }
};
