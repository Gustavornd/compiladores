#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Arvore.hpp"
#include "Gramatica.hpp"
#include "Parser.hpp"
#include "TabelaLR1.hpp"
// #include "src-gram5/Funcao.hpp"
// #include "src-gram5/Analisador.hpp"
#include "arvore/Analisador.hpp"
#include "arvore/Comando.hpp"
#include "arvore/Int.hpp"
#include "arvore/Tipos.hpp"

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 1) {
    cerr << "Parametros nomes dos arquivos: 1) csv com gramática e 2) csv com "
            "tabela LR1"
         << endl;
    return 1;
  }
  string nome_gramatica, nome_tab_lr1;
  if (argc == 1) {
    // cerr << "Valores padrao utilizados: gramatica.conf e tabela_lr1.conf" <<
    // endl;
    nome_gramatica = string("gramatica.conf");
    nome_tab_lr1 = string("tabela_lr1.conf");
  } else {
    nome_gramatica = string(argv[1]);
    nome_tab_lr1 = string(argv[2]);
  }

  ifstream arq_gramatica(nome_gramatica);
  ifstream arq_tabela_lr1(nome_tab_lr1);
  if (arq_tabela_lr1.fail() || arq_gramatica.fail()) {
    cerr << "Falha ao abrir arquivos: "
         << ((arq_gramatica.fail()) ? nome_gramatica : "") << ", "
         << ((arq_tabela_lr1.fail()) ? nome_tab_lr1 : "") << endl;
    return 1;
  }
  Parser parser(arq_gramatica, arq_tabela_lr1);
  parser.tabela.debug();
  parser.gram.debug();

  Arvore_parse arv = parser.executa_parse(cin);
  cerr << "Parse executado" << endl;
  // arv.debug();
  // arv.imprime(arv.raiz);
  Comando *comando = Comando::extrai_comando(arv.raiz->filhos[0]);
  vector<Valor *> valores;
  Int *v = new Int();
  v->tipo = TIPO_INT;
  v->valor = 3;
  valores.push_back(v);
  Analisador analisador;
  auto valor = analisador.calcula_ultimo_valor(comando, valores);
  if (valor) {
    valor->debug();
  } else {
    cerr << "Erro de Sintaxe" << endl;
  }
  return 0;
}
