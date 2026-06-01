#include "Int.hpp"

Int *Int::extrai_int(No_arv_parse *no)
{
    Int *i = new Int();
    i->valor = stoi(no->dado_extra);

    return i;
}

void *Int::aloca_valor()
{
    int *v = new int;
    (*v) = valor;

    return (void *)v;
}
