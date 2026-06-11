#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Valor.hpp"
#include <vector>

class Array : public Valor {
public:
    std::vector<Valor*> elementos; // Guarda os ponteiros para os itens reais
    
    Array();
    void* aloca_valor() override;
};
#endif