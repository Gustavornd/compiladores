#pragma once
#define EXPRESSAO_FUNCAO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"
#include "Identificador.hpp"
#include "Variavel.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class ExpressaoFuncao : public Expressao {
public:
  ExpressaoFuncao(No_arv_parse *no);
  ~ExpressaoFuncao() {}

  Identificador *nome_funcao;
  Identificador *tipo_retorno = nullptr;
  vector<Variavel *> parametros;
  Expressao *expressao;
  Valor *calcula_valor(vector<Valor *> &params);

  void debug() {
    cout << "Expressao de Funcao: " << nome_funcao->valor
         << " Tipo de Retorno: " << (tipo_retorno ? tipo_retorno->valor : "")
         << endl;
    cout << "{" << endl;
    if (parametros.size() > 0) {
      cout << "Parâmetros: " << endl;
      for (int i = 0; i < parametros.size(); i++) {
        parametros[i]->debug();
      }
    }
    expressao->debug();
    cout << "}" << endl;
  }
};
