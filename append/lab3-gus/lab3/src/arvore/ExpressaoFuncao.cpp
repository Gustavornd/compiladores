#include "ExpressaoFuncao.hpp"
#include "Identificador.hpp"
#include "Tipos.hpp"

ExpressaoFuncao::ExpressaoFuncao(No_arv_parse *no) {
  this->nome_funcao =
      Identificador::extrai_identificador(no->filhos[0]->filhos[1]);
  if (no->regra == 19) {
    this->tipo_retorno =
        Identificador::extrai_identificador(no->filhos[0]->filhos[4]);
  }
  this->parametros = Variavel::extrai_parametros(no->filhos[0]);
  this->expressao = Expressao::extrai_expressao(no->filhos[0]->filhos.back());
}

Valor *ExpressaoFuncao::calcula_valor(vector<Valor *> &params) {
  if (params.size() < parametros.size()) {
    cerr << "Parâmetros insuficientes" << endl;
    return nullptr;
  }

  for (int i = 0; i < parametros.size(); i++) {
    if (parametros[i]->tipo_variavel) {
      if (parametros[i]->tipo_variavel->valor != params[i]->tipo) {
        cerr << "Tipos de parâmetros incorretos" << endl;
        return nullptr;
      }
    } else {
      if (!params[i]->tipo.empty()) {
        auto tipo = new Identificador();
        tipo->tipo = TIPO_ID;
        tipo->valor = params[i]->tipo;

        parametros[i]->tipo_variavel = tipo;
      }
    }
    Tipos::adiciona_valor_tabela(parametros[i]->nome_variavel->valor,
                                 parametros[i]->tipo_variavel->valor,
                                 params[i]);
  }

  return expressao->calcula_valor(params);
}
