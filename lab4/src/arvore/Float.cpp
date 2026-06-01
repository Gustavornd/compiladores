#include "Float.hpp"

Float *Float::extrai_float(No_arv_parse *no)
{
    Float *f = new Float();
    f->valor = stof(no->dado_extra);
    return f;
}

void *Float::aloca_valor()
{
    float *v = new float;
    (*v) = valor;

    return (void *)v;
}
