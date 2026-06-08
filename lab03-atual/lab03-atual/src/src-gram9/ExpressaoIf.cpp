#include "ExpressaoIf.hpp"
#include "Bool.hpp"
#include "Expressao.hpp"
#include "Tipos.hpp"
ExpressaoIf::ExpressaoIf(No_arv_parse *no) {

  if (no->regra == 41) {
    condicao = Expressao::extrai_expressao(no->filhos[1]);
    resultado = Expressao::extrai_expressao(no->filhos[3]);
  }
  if (no->regra == 43) {
    condicao = Expressao::extrai_expressao(no->filhos[2]);
    resultado = Expressao::extrai_expressao(no->filhos[4]);
  }
  if (no->filhos[4]->regra == 42) {
    continuacao = Expressao::extrai_expressao(no->filhos[4]->filhos[1]);
  }

  if (no->filhos[4]->regra == 43) {
    continuacao = new ExpressaoIf(no->filhos[4]);
  }
}

Valor *ExpressaoIf::calcula_valor(vector<Valor *> &params) {
  auto val_condicao = condicao->calcula_valor(params);

  if (!val_condicao)
    return nullptr;
  if (val_condicao->tipo == TIPO_ID) {
    val_condicao = ((Identificador *)val_condicao)->get_valor();
  }

  if (val_condicao->tipo != TIPO_BOOL) {
    cerr << "Tipo inválido, esperado booleano" << endl;
    return nullptr;
  }

  if (((Bool *)val_condicao)->valor) {
    return resultado->calcula_valor(params);
  } else {
    if (continuacao) {
      return continuacao->calcula_valor(params);
    }
  }
  return nullptr;
}
