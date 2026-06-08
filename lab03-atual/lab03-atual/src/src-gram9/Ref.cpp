#include "Ref.hpp"
#include "Valor.hpp"
Ref *Ref::extrai_ref(No_arv_parse *no) {
  Ref *r = new Ref();
  r->valor = Valor::extrai_valor(no);
  return r;
}

void *Ref::aloca_valor() { return valor->aloca_valor(); }
