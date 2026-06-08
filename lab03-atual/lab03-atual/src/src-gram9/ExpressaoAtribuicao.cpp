
#include "ExpressaoAtribuicao.hpp"
#include "Expressao.hpp"
#include "Float.hpp"
#include "Identificador.hpp"
#include "Int.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"
ExpressaoAtribuicao::ExpressaoAtribuicao(No_arv_parse *no) {
  esquerda = Expressao::extrai_expressao(no->filhos[0]);
  direita = Expressao::extrai_expressao(no->filhos[2]);
}
Valor *ExpressaoAtribuicao::calcula_valor(vector<Valor *> &params) {
  auto val_esq = esquerda->calcula_valor(params);
  auto val_dir = direita->calcula_valor(params);
  if (!val_esq || !val_dir)
    return nullptr;

  if (val_esq->tipo != TIPO_ID) {
    cerr << "Tipo invalido em atribuicao" << endl;
  }
  auto val = ((Identificador *)val_esq)->get_valor();

  if (val->tipo != TIPO_REF_FLOAT && val->tipo != TIPO_REF_BOOL &&
      val->tipo != TIPO_REF_INT) {
    cerr << "Tipo inválido em atribuiçao" << endl;
    return nullptr;
  }

  if (val_dir->tipo == TIPO_ID) {
    val_dir = ((Identificador *)val_dir)->get_valor();
  }

  if (((Ref *)val)->valor->tipo == val_dir->tipo) {
    auto id = ((Identificador *)val_esq)->valor;
    Tipos::adiciona_valor_tabela(id, val->tipo, val_dir);
  }

  return val_esq;
}
