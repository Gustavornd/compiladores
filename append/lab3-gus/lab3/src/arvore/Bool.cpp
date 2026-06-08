#include "Bool.hpp"

Bool *Bool::extrai_bool(No_arv_parse *no)
{
    Bool *b = new Bool();

    b->valor = (no->dado_extra == "true");

    return b;
}

void *Bool::aloca_valor()
{
    bool *v = new bool;
    (*v) = valor;

    return (void *)v;
}
