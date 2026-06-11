#include "ExpressaoMenorIgual.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Tipos.hpp"

ExpressaoMenorIgual::ExpressaoMenorIgual(No_arv_parse *no) {
  this->esquerda = Expressao::extrai_expressao(no->filhos[0]);
  this->direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoMenorIgual::calcula_valor(vector<Valor *> &params) {
  auto val1 = esquerda->calcula_valor(params);
  auto val2 = direita->calcula_valor(params);

  if (!val1 || !val2) return nullptr;
  if (val1->tipo == TIPO_ID) val1 = ((Identificador *)val1)->get_valor();
  if (val2->tipo == TIPO_ID) val2 = ((Identificador *)val2)->get_valor();

  if (val1->tipo == val2->tipo) {
    Bool *resultado = new Bool();
    resultado->tipo = TIPO_BOOL;
    if (val1->tipo == TIPO_INT) {
      resultado->valor = ((Int *)val1)->valor <= ((Int *)val2)->valor;
    } else if (val1->tipo == TIPO_FLOAT) {
      resultado->valor = ((Float *)val1)->valor <= ((Float *)val2)->valor;
    } else {
      cerr << "Erro: Menor ou Igual (<=) com tipos invalidos" << endl;
      return nullptr;
    }
    return resultado;
  }
  return nullptr;
}