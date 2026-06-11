#include "Funcao.hpp"
#include "../debug-util.hpp"
#include "Expressao.hpp"
#include <iostream>

Funcao::Funcao() {
  tipo_retorno = NULL;
  nome_funcao = NULL;
  corpo = NULL;
}

// Função auxiliar recursiva para localizar o nó de declaração da função na árvore
No_arv_parse* encontrar_no_funcao(No_arv_parse* no) {
    if (no == NULL) return NULL;
    if (no->simb == "FUNCAO" || no->simb == "FUNCAO_RETORNO") return no;
    
    for (auto filho : no->filhos) {
        No_arv_parse* res = encontrar_no_funcao(filho);
        if (res != NULL) return res;
    }
    return NULL;
}

Funcao* Funcao::extrai_funcao(No_arv_parse *no_raiz) {
  No_arv_parse* no_func = encontrar_no_funcao(no_raiz);
  if (no_func == NULL) return NULL;

  Funcao* res = new Funcao();

  // A extração agora utiliza o método estático atualizado e passa o nó da função diretamente.
  // A lógica de navegação dos filhos (regra 21, regra 27, etc) ocorre dentro de Variavel::extrai_parametros.
  res->parametros = Variavel::extrai_parametros(no_func);

  if (no_func->simb == "FUNCAO_RETORNO") {
      // Regra: LET REC ID PARAMS DOISPONTO ID IGUAL EXPR
      if (no_func->filhos.size() == 8 && no_func->filhos[1]->simb == "REC") {
          res->nome_funcao = ID::extrai_ID(no_func->filhos[2]);
          res->tipo_retorno = Tipo::extrai_Tipo(no_func->filhos[5]);
          res->corpo = Expressao::extrai_expressao(no_func->filhos[7]);
      }
      // Regra: LET ID PARAMS DOISPONTO ID IGUAL EXPR
      else if (no_func->filhos.size() == 7) {
          res->nome_funcao = ID::extrai_ID(no_func->filhos[1]);
          res->tipo_retorno = Tipo::extrai_Tipo(no_func->filhos[4]);
          res->corpo = Expressao::extrai_expressao(no_func->filhos[6]);
      }
  } 
  else if (no_func->simb == "FUNCAO") {
      // Regra: LET REC ID PARAMS IGUAL EXPR
      if (no_func->filhos.size() == 6 && no_func->filhos[1]->simb == "REC") {
          res->nome_funcao = ID::extrai_ID(no_func->filhos[2]);
          res->tipo_retorno = NULL; // Tipo inferido implicitamente
          res->corpo = Expressao::extrai_expressao(no_func->filhos[5]);
      }
      // Regra: LET ID PARAMS IGUAL EXPR
      else if (no_func->filhos.size() == 5) {
          res->nome_funcao = ID::extrai_ID(no_func->filhos[1]);
          res->tipo_retorno = NULL;
          res->corpo = Expressao::extrai_expressao(no_func->filhos[4]);
      }
  }

  return res;
}

void Funcao::debug() {
  cerr << "Funcao:[retorno=" << (tipo_retorno ? tipo_retorno->nome() : "INFERIDO") << "][nome=" << (nome_funcao ? nome_funcao->nome : "NULL") << "]" << endl;
  cerr << "      (Param:(";
  
  for (size_t i_par = 0; i_par < parametros.size(); ++i_par) {
    // Acessando propriedades atualizadas da classe Variavel (tipo_variavel e nome_variavel)
    string tipo_str = (parametros[i_par]->tipo_variavel == NULL) ? "TIPO_INFERIDO" : parametros[i_par]->tipo_variavel->valor;
    string nome_str = (parametros[i_par]->nome_variavel == NULL) ? "NULL" : parametros[i_par]->nome_variavel->valor;
    
    cerr << tipo_str << " " << nome_str << ", ";
  }
  
  cerr << ") { " << endl;
  if (corpo) {
      corpo->debug();
  }
  cerr << "}" <<  endl;
}