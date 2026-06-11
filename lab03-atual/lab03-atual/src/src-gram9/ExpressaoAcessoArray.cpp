#include "ExpressaoAcessoArray.hpp"
#include "Array.hpp"
#include "Int.hpp"
#include "Identificador.hpp"
#include "Tipos.hpp"

ExpressaoAcessoArray::ExpressaoAcessoArray(No_arv_parse *no) {
    // OCaml array access: EXPR_P -> EXPR_P PONTO EPAR EXPR DPAR (ex: arr.(i))
    array_expr = Expressao::extrai_expressao(no->filhos[0]);
    indice_expr = Expressao::extrai_expressao(no->filhos[3]); // O índice 'i'
}

Valor *ExpressaoAcessoArray::calcula_valor(vector<Valor *> &params) {
    auto arr_val = array_expr->calcula_valor(params);
    auto ind_val = indice_expr->calcula_valor(params);

    if (!arr_val || !ind_val) return nullptr;

    if (arr_val->tipo == TIPO_ID) {
        arr_val = ((Identificador*)arr_val)->get_valor();
    }
    if (ind_val->tipo == TIPO_ID) {
        ind_val = ((Identificador*)ind_val)->get_valor();
    }

    // O código 999 é a nossa classe Array
    if (arr_val->tipo == "TIPO_ARRAY" && ind_val->tipo == TIPO_INT) {
        Array* arr = (Array*)arr_val;
        int i = ((Int*)ind_val)->valor;
        
        if (i >= 0 && i < (int)arr->elementos.size()) {
            // Retorna o PONTEIRO DIRETO da memória. É isto que permite o <- alterar o valor!
            return arr->elementos[i];
        } else {
            cerr << "Erro Fatal: OutOfBounds. Indice de array (" << i << ") fora dos limites!" << endl;
        }
    } else {
        cerr << "Erro de Tipo: Tentativa de indexar uma variavel que nao e array." << endl;
    }
    return nullptr;
}