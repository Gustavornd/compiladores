#include "Array.hpp"

Array::Array() {
    this->tipo = "TIPO_ARRAY"; // Usando 999 para identificar que é um Array
}

void* Array::aloca_valor() {
    // Retorna a si próprio como ponteiro de memória
    return this;
}