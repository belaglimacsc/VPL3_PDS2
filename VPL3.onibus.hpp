#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include <string>
using namespace std;

struct onibus{
    string placa;
    int cap_max;
    int lot_atual;

    void construtor(string, int);
    int subir_passageiros(int);
    int descer_passageiros(int);
    int transfere_passageiros(struct onibus *, int);
    void imprimir_estado();
};

#endif