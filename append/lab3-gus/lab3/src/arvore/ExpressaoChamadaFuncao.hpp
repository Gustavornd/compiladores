#pragma once
#include <system_error>
#define EXPRESSAO_CHAMADA_FUNCAO_HPP
#include "../Arvore.hpp"
#include "Expressao.hpp"
#include "Identificador.hpp"
#include <vector>
using namespace std;
class ExpressaoChamadaFuncao : public Expressao {
public:
  ExpressaoChamadaFuncao(No_arv_parse *no);
  static vector<Expressao *> extrai_argumentos(No_arv_parse *no);
  Valor *calcula_valor(vector<Valor *> &params);
  void debug() {
    cout << "Expressão Chamada de Funcao" << endl;
    cout << "{" << endl;
    cout << "Nome: " << nome_funcao->valor << endl;
    for (auto &val : argumentos) {
      val->debug();
    }
    cout << "}" << endl;
  }
  Identificador *nome_funcao;
  vector<Expressao *> argumentos;
};
