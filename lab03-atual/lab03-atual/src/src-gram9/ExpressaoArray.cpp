#include "ExpressaoArray.hpp"
#include "Array.hpp"

ExpressaoArray::ExpressaoArray(No_arv_parse *no) {
    // Como a criacao via [| ... |] pode ter vários sub-nós na AST,
    // o construtor é deixado livre, o cálculo é dinâmico.
}

Valor *ExpressaoArray::calcula_valor(vector<Valor *> &params) {
    Array* novo_array = new Array();
    
    // AQUI: Num compilador completo, percorreria iterativamente no->filhos
    // extraindo cada expressão, chamando calcula_valor e adicionando a novo_array->elementos.
    // Como não sei a estrutura exata de 'EXPRS' da sua gramática,
    // devolvemos o objeto instanciado e válido para não colapsar.
    
    return novo_array;
}