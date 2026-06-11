#include "ExpressaoInfix.hpp"
#include "Float.hpp"
#include "Identificador.hpp"
#include "Tipos.hpp"

ExpressaoInfix::ExpressaoInfix(No_arv_parse *no) {
  esquerda = Expressao::extrai_expressao(no->filhos[0]);
  // O símbolo está no nó do meio (filhos[1])
  simbolo = no->filhos[1]->dado_extra; 
  direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoInfix::calcula_valor(vector<Valor *> &params) {
  auto val1 = esquerda->calcula_valor(params);
  auto val2 = direita->calcula_valor(params);

  if (!val1 || !val2) return nullptr;
  if (val1->tipo == TIPO_ID) val1 = ((Identificador *)val1)->get_valor();
  if (val2->tipo == TIPO_ID) val2 = ((Identificador *)val2)->get_valor();

  // Tratar a soma flutuante (+.) do OCaml
  if (simbolo == "+.") {
      if (val1->tipo == TIPO_FLOAT && val2->tipo == TIPO_FLOAT) {
        Float *resultado = new Float();
        resultado->tipo = TIPO_FLOAT;
        resultado->valor = ((Float *)val1)->valor + ((Float *)val2)->valor;
        return resultado;
      } else {
        cerr << "Erro de tipo: Operador '+.' espera argumentos float" << endl;
      }
  } else {
      cerr << "Aviso: Operador infix desconhecido: " << simbolo << endl;
  }
  return nullptr;
}