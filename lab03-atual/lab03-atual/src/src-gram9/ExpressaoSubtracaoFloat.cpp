#include "ExpressaoSubtracaoFloat.hpp"
#include "Float.hpp"
#include "Identificador.hpp"
#include "Tipos.hpp"

ExpressaoSubtracaoFloat::ExpressaoSubtracaoFloat(No_arv_parse *no) {
  esquerda = Expressao::extrai_expressao(no->filhos[0]);
  direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoSubtracaoFloat::calcula_valor(vector<Valor *> &params) {
  auto val1 = esquerda->calcula_valor(params);
  auto val2 = direita->calcula_valor(params);

  if (!val1 || !val2) return nullptr;
  if (val1->tipo == TIPO_ID) val1 = ((Identificador *)val1)->get_valor();
  if (val2->tipo == TIPO_ID) val2 = ((Identificador *)val2)->get_valor();

  // No OCaml, operadores com ponto exigem obrigatoriamente Float
  if (val1->tipo == TIPO_FLOAT && val2->tipo == TIPO_FLOAT) {
    Float *resultado = new Float();
    resultado->tipo = TIPO_FLOAT;
    resultado->valor = ((Float *)val1)->valor - ((Float *)val2)->valor;
    return resultado;
  } else {
    cerr << "Erro de tipo: Operador OCaml '-.' espera argumentos float" << endl;
    return nullptr;
  }
}