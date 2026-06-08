#include "ExpressaoValor.hpp"
#include "Tipos.hpp"

ExpressaoValor::ExpressaoValor(No_arv_parse *no) {
  this->valor = Valor::extrai_valor(no);
}

Valor *ExpressaoValor::calcula_valor(vector<Valor *> &params) {
  // if (valor->tipo == TIPO_ID) {
  //   return ((Identificador *)valor)->get_valor();
  // }

  return valor;
}
