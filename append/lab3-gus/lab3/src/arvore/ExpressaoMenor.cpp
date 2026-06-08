#include "ExpressaoMenor.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Tipos.hpp"
ExpressaoMenor::ExpressaoMenor(No_arv_parse *no) {
  this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
  this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoMenor::calcula_valor(vector<Valor *> &params) {
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
      Bool *resultado = new Bool();
      resultado->tipo = TIPO_BOOL;
      resultado->valor = ((Int *)val1)->valor < ((Int *)val2)->valor;
      return resultado;
    } else if (val1->tipo == TIPO_FLOAT) {
      Bool *resultado = new Bool();
      resultado->tipo = val1->tipo;
      resultado->valor = ((Float *)val1)->valor < ((Float *)val2)->valor;
      return resultado;
    } else {
      cerr << "Tipos inválidos no Menor" << endl;
    }
  } else {
    cerr << "Tipos inválidos no Menor" << endl;
  }

  return nullptr;
}
