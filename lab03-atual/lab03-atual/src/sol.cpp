#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>   
#include <sstream>
#include <map>
#include <stack>
using namespace std;

#include "Gramatica.hpp"
#include "TabelaLR1.hpp"
#include "Arvore.hpp"
#include "Parser.hpp"
#include "Funcao.hpp"
#include "Analisador.hpp"
#include "ValorLiteral.hpp"

int main(int argc, char * argv[]) {
  // Ajustado para receber o programa (argv[0]) + 3 arquivos, totalizando argc == 4.
  // Ou argc == 1 para usar os valores padrão.
  if (argc != 4 && argc != 1) {
    cerr << "Parametros nomes dos arquivos: " 
        << argv[0] 
        << " [gramatica.site] [tabela_lr1.conf] [arquivo.params]"
        << endl;

    return 1;
  }

  string nome_gramatica, nome_tab_lr1, nome_params;
  if (argc == 1) {
    nome_gramatica = string("gramatica9.site");
    nome_tab_lr1 = string("tabela_lr1.conf");
    nome_params = string("arquivo.params"); // Valor padrão para o terceiro arquivo
  } else {
    nome_gramatica = string(argv[1]);
    nome_tab_lr1 = string(argv[2]);
    nome_params = string(argv[3]);
  }

  ifstream arq_gramatica(nome_gramatica);
  ifstream arq_tabela_lr1(nome_tab_lr1);
  ifstream arq_params(nome_params); // Abertura do arquivo de parâmetros

  // Adicionada verificação de falha também para o arquivo de parâmetros
  if (arq_tabela_lr1.fail() || arq_gramatica.fail() || arq_params.fail()) {
    cerr << "Falha ao abrir arquivos: " << 
      ((arq_gramatica.fail()) ? nome_gramatica + " " : "") <<
      ((arq_tabela_lr1.fail()) ? nome_tab_lr1 + " " : "") <<
      ((arq_params.fail()) ? nome_params : "") << endl;
    return 1;    
  }

  Parser parser(arq_gramatica, arq_tabela_lr1);
  parser.tabela.debug();
  parser.gram.debug();
  
  Arvore_parse arv = parser.executa_parse(cin);
  cerr << "Parse executado" << endl;
  arv.debug();
  Funcao* func = Funcao::extrai_funcao(arv.raiz);
  func->debug();

  vector<ValorLiteral> parametros_passados;


  for (int i = 1; i <= 3; ++i) {
    ValorLiteral valor_parametro;
    valor_parametro.tipo = new Tipo(Tipo::INT);
    valor_parametro.valor_int = i*10;
    parametros_passados.push_back(valor_parametro);
  }
  

  Analisador ana;
  cout << "Retorno calculado:" << endl;
  cout << ana.calcula_ultimo_valor(func, parametros_passados) << endl;
  
  return 0;
}