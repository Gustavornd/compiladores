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
#include "Util.hpp"
#include <cmath>
using namespace std;

Expressao *Expressao::extrai_expressao(No_arv_parse *no) {
  auto no_exp = get_tipo_expressao(no);

  switch (no_exp->regra) {

  case 11: {
    ExpressaoIn *exp_in = new ExpressaoIn(no_exp);
    return exp_in;
  }
  case 12: {
    ExpressaoDeclaracao *exp_dec = new ExpressaoDeclaracao(no_exp);
    return exp_dec;
  }
  case 13: {
    ExpressaoDeclaracao *exp_dec = new ExpressaoDeclaracao(no_exp);
    return exp_dec;
  }
  case 14: {
    ExpressaoDeclaracao *exp_dec = new ExpressaoDeclaracao(no_exp);
    return exp_dec;
  }
  case 15: {
    ExpressaoDeclaracao *exp_dec = new ExpressaoDeclaracao(no_exp);
    return exp_dec;
  }
  case 16: {
    ExpressaoDeclaracao *exp_dec = new ExpressaoDeclaracao(no_exp);
    return exp_dec;
  }
  case 17: {
    ExpressaoDeclaracao *exp_dec = new ExpressaoDeclaracao(no_exp);
    return exp_dec;
  }
  // EXPR_A -> FUNCAO
  case 18: {
    ExpressaoFuncao *expr_func = new ExpressaoFuncao(no_exp);
    return expr_func;
  }
  // EXPR_A -> FUNCAO_RETORNO
  case 19: {
    ExpressaoFuncao *expr_func = new ExpressaoFuncao(no_exp);
    return expr_func;
  }
  case 35: {
    ExpressaoSeparador *exp_sep = new ExpressaoSeparador(no_exp);
    return exp_sep;
  }
  case 39: {
    ExpressaoWhile *exp_while = new ExpressaoWhile(no_exp);
    return exp_while;
  }
  case 41: {
    ExpressaoIf *exp_if = new ExpressaoIf(no_exp);
    return exp_if;
  }
  case 47: {
    ExpressaoAtribuicao *expr_attr = new ExpressaoAtribuicao(no_exp);
    return expr_attr;
  }
  case 49: {
    ExpressaoOU *exp_ou = new ExpressaoOU(no_exp);
    return exp_ou;
  }
  case 50: {
    ExpressaoOU *exp_ou = new ExpressaoOU(no_exp);
    return exp_ou;
  }
  case 52: {
    ExpressaoE *exp_e = new ExpressaoE(no_exp);
    return exp_e;
  }
  case 53: {
    ExpressaoE *exp_e = new ExpressaoE(no_exp);
    return exp_e;
  }
  case 57: {
    ExpressaoIgual *exp_igual = new ExpressaoIgual(no_exp);
    return exp_igual;
  }
  case 59: {
    ExpressaoMenor *exp_menor = new ExpressaoMenor(no_exp);
    return exp_menor;
  }
  case 60: {
    ExpressaoMaior *exp_maior = new ExpressaoMaior(no_exp);
    return exp_maior;
  }
  case 67: {
    ExpressaoSoma *expr_soma = new ExpressaoSoma(no_exp);
    return expr_soma;
  }
  case 68: {
    ExpressaoSubtracao *expr_sub = new ExpressaoSubtracao(no_exp);
    return expr_sub;
  }
  case 73: {
    ExpressaoMod *expr_mod = new ExpressaoMod(no_exp);
    return expr_mod;
  }
  // EXPR_J -> EXPR_J AST EXP_K
  case 76: {
    ExpressaoMultiplicacao *expr_mult = new ExpressaoMultiplicacao(no_exp);
    return expr_mult;
  }
  case 77: {
    ExpressaoDivisao *expr_div = new ExpressaoDivisao(no_exp);
    return expr_div;
  }
  case 86: {
    ExpressaoChamadaFuncao *expr_call = new ExpressaoChamadaFuncao(no_exp);
    return expr_call;
  }
  case 87: {
    ExpressaoChamadaFuncao *expr_call = new ExpressaoChamadaFuncao(no_exp);
    return expr_call;
  }
  case 91: {
    ExpressaoPrefixo *expr_pre = new ExpressaoPrefixo(no_exp);
    return expr_pre;
  }
  case 93: {
    ExpressaoParenteses *exp_par = new ExpressaoParenteses(no_exp);
    return exp_par;
  }
  case 94: {
    ExpressaoParenteses *exp_par = new ExpressaoParenteses(no_exp);
    return exp_par;
  } // EXPR_P -> ID
  case 95: {
    ExpressaoValor *expr_val = new ExpressaoValor(no_exp);
    return expr_val;
  }
  // EXPR_P -> INT
  case 96: {
    ExpressaoValor *expr_val = new ExpressaoValor(no_exp);
    return expr_val;
  }
  // EXPR_P -> FLOAT
  case 97: {
    ExpressaoValor *expr_val = new ExpressaoValor(no_exp);
    return expr_val;
  }
  // EXPR_P -> FALSE
  case 100: {
    ExpressaoValor *expr_val = new ExpressaoValor(no_exp);
    return expr_val;
  }
  // EXPR_P -> TRUE
  case 101: {
    ExpressaoValor *expr_val = new ExpressaoValor(no_exp);
    return expr_val;
  }
  case 102: {
    ExpressaoValor *expr_val = new ExpressaoValor(no_exp);
    return expr_val;
  }
  }
}

No_arv_parse *Expressao::get_tipo_expressao(No_arv_parse *no) {
  auto regras_transicao = Util::get_transicao_exp();
  bool is_transicao = true;
  auto atual = no;

  while (is_transicao) {
    bool mudou = false;
    for (int i = 0; i < regras_transicao.size(); i++) {
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
}
