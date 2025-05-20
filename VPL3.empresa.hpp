#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "Onibus.hpp"
#include <string>

using namespace std;
struct empresa{
    int num_onibus;
    onibus** vet_ptr_onibus = new onibus*[20];

    void construtor();
    onibus* adicionar_onibus(string, int);
    onibus* buscar_onibus(string);
    void imprimir_estado();
};
#endif