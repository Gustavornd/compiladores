#include "Expressao.hpp"
#include "ExpressaoAtribuicao.hpp"
#include "ExpressaoChamadaFuncao.hpp"
#include "ExpressaoDeclaracao.hpp"
#include "ExpressaoDivisao.hpp"
#include "ExpressaoE.hpp"
#include "ExpressaoFuncao.hpp"
#include "ExpressaoIf.hpp"
#include "ExpressaoIgual.hpp"
#include "ExpressaoIn.hpp"
#include "ExpressaoMaior.hpp"
#include "ExpressaoMenor.hpp"
#include "ExpressaoMod.hpp"
#include "ExpressaoMultiplicacao.hpp"
#include "ExpressaoOU.hpp"
#include "ExpressaoParenteses.hpp"
#include "ExpressaoPrefixo.hpp"
#include "ExpressaoSeparador.hpp"
#include "ExpressaoSoma.hpp"
#include "ExpressaoSubtracao.hpp"
#include "ExpressaoValor.hpp"
#include "ExpressaoWhile.hpp"
#include "ExpressaoIgualdade.hpp"
#include "ExpressaoNegacao.hpp"
#include "ExpressaoVariavel.hpp"

// --- NOVAS REGRAS E IMPLEMENTAÇÕES ADICIONADAS ---
#include "ExpressaoMaiorIgual.hpp"
#include "ExpressaoMenorIgual.hpp"
#include "ExpressaoDiferente.hpp"
#include "ExpressaoSubtracaoFloat.hpp"
#include "ExpressaoMultiplicacaoFloat.hpp"
#include "ExpressaoDivisaoFloat.hpp"
#include "ExpressaoInfix.hpp"
#include "ExpressaoSetae.hpp"
#include "ExpressaoAcessoArray.hpp"
#include "ExpressaoArray.hpp"
#include "Array.hpp"

#include "Float.hpp"
#include "ID.hpp"
#include "Identificador.hpp"
#include "Int.hpp"
#include "Ref.hpp"
#include "Tipo.hpp"
#include "Tipos.hpp"
#include "Unit.hpp"
#include "Util.hpp"
#include "Valor.hpp"
#include "ValorLiteral.hpp"
#include "Variavel.hpp"

#include <cmath>
#include <iostream>

using namespace std;

Expressao *Expressao::extrai_expressao(No_arv_parse *no) {
  auto no_exp = get_tipo_expressao(no);

  switch (no_exp->regra) {

  // --- ESTRUTURAS DE BLOCO E ESCOPO ---
  case 11: return new ExpressaoIn(no_exp);
  case 12: case 13: case 14: case 15: case 16: case 17: 
      return new ExpressaoDeclaracao(no_exp);

  // --- FUNÇÕES ---
  case 18: case 19: return new ExpressaoFuncao(no_exp);
  case 86: case 87: return new ExpressaoChamadaFuncao(no_exp);

  // --- CONTROLE DE FLUXO ---
  case 35: return new ExpressaoIn(no_exp); 
  case 39: return new ExpressaoWhile(no_exp);
  case 41: return new ExpressaoIf(no_exp);

  // --- ATRIBUIÇÃO E MUTAÇÃO (OCAML) ---
  case 46: return new ExpressaoSetae(no_exp);          // Operador '<-'
  case 47: return new ExpressaoAtribuicao(no_exp);     // Operador ':='

  // --- LÓGICA E RELACIONAIS ---
  case 49: case 50: return new ExpressaoOU(no_exp);
  case 52: case 53: return new ExpressaoE(no_exp);
  case 55: return new ExpressaoMaiorIgual(no_exp);     // >=
  case 56: return new ExpressaoMenorIgual(no_exp);     // <=
  case 57: return new ExpressaoIgual(no_exp);          // Igualdade
  case 59: return new ExpressaoMenor(no_exp);
  case 60: return new ExpressaoMaior(no_exp);
  case 62: return new ExpressaoDiferente(no_exp);      // Operador '<>'

  // --- ARITMÉTICA INTEIRA e PONTO FLUTUANTE ---
  case 67: return new ExpressaoSoma(no_exp);
  case 68: return new ExpressaoSubtracao(no_exp);
  case 69: return new ExpressaoSubtracaoFloat(no_exp); // -.
  case 70: return new ExpressaoInfix(no_exp);          // +. e personalizados
  case 73: return new ExpressaoMod(no_exp);
  case 74: return new ExpressaoDivisaoFloat(no_exp);   // /.
  case 75: return new ExpressaoMultiplicacaoFloat(no_exp); // *.
  case 76: return new ExpressaoMultiplicacao(no_exp);
  case 77: return new ExpressaoDivisao(no_exp);

  // --- PREFIXO E PARÊNTESES ---
  case 91: return new ExpressaoPrefixo(no_exp);
  case 93: case 94: return new ExpressaoParenteses(no_exp);

  // --- VALORES, LITERAIS E VARIÁVEIS ---
  case 95: return new ExpressaoVariavel(no_exp);       // ID identificador
  case 96: case 97: case 100: case 101: case 102:
      return new ExpressaoValor(no_exp);               // INT, FLOAT, BOOL, UNIT

  // --- INFRAESTRUTURA DE ARRAYS ---
  case 103: return new ExpressaoAcessoArray(no_exp);   // Leitura via a.(i)
  case 104: case 105: case 106: return new ExpressaoArray(no_exp); // Criação [| ... |]

  // --- DEFAULT DE SEGURANÇA ---
  default:
      cerr << "ERRO: Regra " << no_exp->regra << " (" << no_exp->simb << ") nao mapeada!" << endl;
      return NULL;
  }
}

No_arv_parse *Expressao::get_tipo_expressao(No_arv_parse *no) {
  auto regras_transicao = Util::get_transicao_exp();
  bool is_transicao = true;
  auto atual = no;

  while (is_transicao) {
    bool mudou = false;
    for (int i = 0; i < (int)regras_transicao.size(); i++) {
      if (atual->regra == regras_transicao[i]) {
        atual = atual->filhos[0];
        mudou = true;
        break;
      }
    }

    if (!mudou) {
      return atual;
    }
  }
  return atual;
}