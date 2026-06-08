#include "ExpressaoPrefixo.hpp"
#include "Ref.hpp"
#include "Tipos.hpp"
ExpressaoPrefixo::ExpressaoPrefixo(No_arv_parse *no) {
  operador = no->filhos[0]->dado_extra;
  expressao = Expressao::extrai_expressao(no->filhos[1]);
}

Valor *ExpressaoPrefixo::calcula_valor(vector<Valor *> &params) {
  if (operador == "!") {
    Valor *val = expressao->calcula_valor(params);
    if (val->tipo == TIPO_ID) {
      val = ((Identificador *)val)->get_valor();
    }
    if (val->tipo == TIPO_REF_INT || val->tipo == TIPO_REF_FLOAT ||
        val->tipo == TIPO_REF_BOOL) {
      return ((Ref *)val)->valor;
    } else {
      cerr << "Tipo Inválido" << endl;
    }
  }
  return nullptr;
}
