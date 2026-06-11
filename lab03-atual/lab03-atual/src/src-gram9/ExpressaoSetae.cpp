#include "ExpressaoSetae.hpp"
#include "Identificador.hpp"
#include "Int.hpp"
#include "Float.hpp"
#include "Bool.hpp"
#include "Unit.hpp"
#include "Tipos.hpp"

ExpressaoSetae::ExpressaoSetae(No_arv_parse *no) {
    esquerda = Expressao::extrai_expressao(no->filhos[0]);
    direita = Expressao::extrai_expressao(no->filhos[2]);
}

Valor *ExpressaoSetae::calcula_valor(vector<Valor *> &params) {
    auto val_esq = esquerda->calcula_valor(params);
    auto val_dir = direita->calcula_valor(params);

    if (!val_esq || !val_dir) return nullptr;

    // Se o valor a atribuir for uma variável, extraímos o seu conteúdo real
    if (val_dir->tipo == TIPO_ID) {
        val_dir = ((Identificador*)val_dir)->get_valor();
    }

    // A MÁGICA ACONTECE AQUI:
    // O val_esq é um ponteiro para a memória que já está dentro do Array ou Record.
    // Ao modificarmos o seu interior (->valor), alteramos a memória global do C++!
    if (val_esq->tipo == TIPO_INT && val_dir->tipo == TIPO_INT) {
        ((Int*)val_esq)->valor = ((Int*)val_dir)->valor;
    } 
    else if (val_esq->tipo == TIPO_FLOAT && val_dir->tipo == TIPO_FLOAT) {
        ((Float*)val_esq)->valor = ((Float*)val_dir)->valor;
    } 
    else if (val_esq->tipo == TIPO_BOOL && val_dir->tipo == TIPO_BOOL) {
        ((Bool*)val_esq)->valor = ((Bool*)val_dir)->valor;
    } 
    else {
        cerr << "Erro: Incompatibilidade de tipos na mutacao (<-)." << endl;
    }

    // Em OCaml, a atribuição '<-' retorna smepre o tipo Unit ()
    Unit *u = new Unit();
    u->tipo = TIPO_UNIT;
    return u;
}