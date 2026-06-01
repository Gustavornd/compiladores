#include "Valor.hpp"
#include "Int.hpp"
#include "Float.hpp"
#include "Bool.hpp"
#include "Identificador.hpp"
#include "Unit.hpp"
#include "Tipos.hpp"
Valor *Valor::extrai_valor(No_arv_parse *no)
{
    switch (no->regra)
    {
    case 95:
    {
        Identificador *id = Identificador::extrai_identificador(no->filhos[0]);
        id->tipo = TIPO_ID;
        return id;
    }
    case 96:
    {
        Int *i = Int::extrai_int(no->filhos[0]);
        i->tipo = TIPO_INT;
        return i;
    }
    case 97:
    {
        Float *f = Float::extrai_float(no->filhos[0]);
        f->tipo = TIPO_FLOAT;
        return f;
    }
    case 100:
    {
        Bool *b = Bool::extrai_bool(no->filhos[0]);
        b->tipo = TIPO_BOOL;
        return b;
    }
    case 101:
    {
        Bool *b = Bool::extrai_bool(no->filhos[0]);
        b->tipo = TIPO_BOOL;
        return b;
    }
    case 102:
    {
        Unit *u = new Unit();
        u->tipo = TIPO_UNIT;
        return u;
    }
    }
}
