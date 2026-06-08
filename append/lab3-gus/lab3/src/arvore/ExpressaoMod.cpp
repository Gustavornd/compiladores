#include "ExpressaoMod.hpp"
#include "Int.hpp"
#include "Tipos.hpp"

ExpressaoMod::ExpressaoMod(No_arv_parse *no) {
  this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
  this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoMod::calcula_valor(vector<Valor *> &params) {
  auto val1 = esquerda->calcula_valor(params);
  auto val2 = direita->calcula_valor(params);

  if (!val1 || !val2)
    return nullptr;
  if (val1->tipo == TIPO_ID) {
    val1 = ((Identificador *)val1)->get_valor();
  }

  if (val2->tipo == TIPO_ID) {
    val2 = ((Identificador *)val2)->get_valor();
  }

  if (val1->tipo == val2->tipo) {
    if (val1->tipo == TIPO_INT) {
      Int *resultado = new Int();
      resultado->tipo = val1->tipo;
      resultado->valor = ((Int *)val1)->valor % ((Int *)val2)->valor;
      return resultado;
    }
    cerr << "Tipos inválidos no mod" << endl;
  } else {
    cerr << "Tipos inválidos no mod" << endl;
  }

  return nullptr;
}
