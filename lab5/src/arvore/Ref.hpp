#pragma once
#define REF_HPP
#include "../Arvore.hpp"
#include "Valor.hpp"

class Ref : public Valor {
public:
  Valor *valor;

  static Ref *extrai_ref(No_arv_parse *no);
  void *aloca_valor();
  void debug() {
    cout << "Ref: " << endl;
    valor->debug();
  }
};
