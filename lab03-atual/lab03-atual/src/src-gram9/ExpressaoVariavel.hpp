#ifndef _EXPRESSAO_VARIAVEL_HPP_
#define _EXPRESSAO_VARIAVEL_HPP_
#include "Expressao.hpp"
#include "ID.hpp"
using namespace std;

class ExpressaoVariavel : public Expressao {
public:
    Identificador *nome; // Alterado de ID* para Identificador*
    
    ExpressaoVariavel(No_arv_parse *no); // Construtor necessário
    void debug_com_tab(int tab);
};
#endif
