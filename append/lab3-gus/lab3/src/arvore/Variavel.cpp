#include "Variavel.hpp"

vector<Variavel *> Variavel::extrai_parametros(No_arv_parse *no)
{
    if (no->regra == 21 || no->regra == 25)
        return vector<Variavel *>();

    vector<Variavel *> parametros;
    No_arv_parse *no_prox;

    if (no->filhos[2]->regra == 27)
    {
        Variavel *var = new Variavel();
        var->nome_variavel = Identificador::extrai_identificador(no->filhos[2]->filhos[0]);
        no_prox = no->filhos[2]->filhos[1];
        parametros.push_back(var);
    }

    if (no->filhos[2]->regra == 28)
    {
        Variavel *var = new Variavel();
        var->nome_variavel = Identificador::extrai_identificador(no->filhos[2]->filhos[1]);
        var->tipo_variavel = Identificador::extrai_identificador(no->filhos[2]->filhos[3]);
        no_prox = no->filhos[2]->filhos[4];
        parametros.push_back(var);
    }

    auto v = extrai_params_recursivo(no_prox);
    parametros.insert(parametros.end(), v.begin(), v.end());

    return parametros;
}

vector<Variavel *> Variavel::extrai_params_recursivo(No_arv_parse *no)
{
    vector<Variavel *> params;

    // PARAM -> EPAR ID DOISPONTO ID CONT_PARAM
    if (no->regra == 29)
    {
        Variavel *var = new Variavel();
        var->nome_variavel = Identificador::extrai_identificador(no->filhos[1]);
        var->tipo_variavel = Identificador::extrai_identificador(no->filhos[3]);
        params.push_back(var);

        auto v = extrai_params_recursivo(no->filhos[4]);
        params.insert(params.end(), v.begin(), v.end());
    }

    // CONT_PARAM -> DPAR PARAM
    if (no->regra == 30)
    {
        auto v = extrai_params_recursivo(no->filhos[1]);
        params.insert(params.end(), v.begin(), v.end());
    }

    // 31: CONT_PARAM -> ID CONT_PARAM
    // 32: PARAM -> ID PARAM
    if (no->regra == 31 || no->regra == 32)
    {
        Variavel *var = new Variavel();
        var->nome_variavel = Identificador::extrai_identificador(no->filhos[0]);
        params.push_back(var);

        auto v = extrai_params_recursivo(no->filhos[1]);
        params.insert(params.end(), v.begin(), v.end());
    }

    if (no->regra == 33)
    {
        return vector<Variavel *>();
    }

    return params;
}

Variavel *Variavel::extrai_variavel_declaracao(No_arv_parse *no)
{
    Variavel *var = new Variavel();

    var->nome_variavel = Identificador::extrai_identificador(no->filhos[1]);

    if (no->regra == 13 || no->regra == 14 || no->regra == 16 || no->regra == 17)
    {
        var->tipo_variavel = Identificador::extrai_identificador(no->filhos[3]);
        if (no->regra == 14 || no->regra == 17)
        {
            auto id = Identificador::extrai_identificador(no->filhos[4]);
            var->tipo_variavel->une_identificadores(id);
        }
    }

    return var;
}
