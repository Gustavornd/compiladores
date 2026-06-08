#include "ExpressaoDeclaracao.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"
ExpressaoDeclaracao::ExpressaoDeclaracao(No_arv_parse *no) {
  variavel = Variavel::extrai_variavel_declaracao(no);
  expressao = Expressao::extrai_expressao(no->filhos.back());
}

Valor *ExpressaoDeclaracao::calcula_valor(vector<Valor *> &params) {
  auto val = expressao->calcula_valor(params);
  if (!val)
    return nullptr;
  if (val->tipo == TIPO_ID) {
    val = ((Identificador *)val)->get_valor();
  }

  // if (val->tipo == TIPO_REF_FLOAT || val->tipo == TIPO_REF_BOOL ||
  //     val->tipo == TIPO_REF_INT) {
  //   val = ((Ref *)val)->valor;
  // }

  if (!variavel->tipo_variavel) {
    Identificador *nome_tipo = new Identificador();
    nome_tipo->tipo = TIPO_ID;
    nome_tipo->valor = val->tipo;
    variavel->tipo_variavel = nome_tipo;
  }

  Tipos::adiciona_valor_tabela(variavel->nome_variavel->valor,
                               variavel->tipo_variavel->valor, val);

  return val;
}
