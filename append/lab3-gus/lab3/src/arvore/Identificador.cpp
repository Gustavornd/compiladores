#include "Identificador.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"
#include <iostream>
Identificador *Identificador::extrai_identificador(No_arv_parse *no) {
  Identificador *identificador = new Identificador();
  identificador->valor = no->dado_extra;

  return identificador;
}

void Identificador::une_identificadores(Identificador *id) {
  valor = valor + " " + id->valor;
}

void *Identificador::aloca_valor() {
  return Tipos::recupera_valor_tabela(valor).valor_ptr;
}

Valor *Identificador::get_valor() {
  auto val = Tipos::recupera_valor_tabela(valor);

  if (val.tipo == TIPO_INT) {
    Int *i = new Int();
    i->valor = (*(int *)(val.valor_ptr));
    i->tipo = val.tipo;
    return i;
  }
  if (val.tipo == TIPO_FLOAT) {
    Float *f = new Float();
    f->valor = (*(float *)(val.valor_ptr));
    f->tipo = val.tipo;
    return f;
  }
  if (val.tipo == TIPO_BOOL) {
    Bool *b = new Bool();
    b->valor = (*(bool *)(val.valor_ptr));
    b->tipo = val.tipo;
    return b;
  }

  if (val.tipo == TIPO_REF_INT) {
    Ref *r = new Ref();
    Int *v = new Int();

    r->tipo = val.tipo;
    v->tipo = TIPO_INT;
    v->valor = (*(int *)(val.valor_ptr));
    r->valor = v;
    return r;
  }
  if (val.tipo == TIPO_REF_FLOAT) {
    Ref *r = new Ref();
    Float *v = new Float();

    r->tipo = val.tipo;
    v->tipo = TIPO_FLOAT;
    v->valor = (*(float *)(val.valor_ptr));
    r->valor = v;
    return r;
  }
  if (val.tipo == TIPO_REF_BOOL) {
    Ref *r = new Ref();
    Bool *v = new Bool();

    r->tipo = val.tipo;
    v->tipo = TIPO_BOOL;
    v->valor = (*(bool *)(val.valor_ptr));
    r->valor = v;
    return r;
  }

  return nullptr;
}
