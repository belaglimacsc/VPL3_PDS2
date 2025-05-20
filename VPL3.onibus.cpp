#include "Onibus.hpp"
#include <string>
#include <iostream>
using namespace std;

void onibus::construtor(string placa1, int cap_max1){
    this->placa = placa1;
    this->cap_max = cap_max1;
    this->lot_atual = 0;
}
int onibus::subir_passageiros(int num){
    this->lot_atual +=num;

    return this->lot_atual;
}
int onibus::descer_passageiros(int num){
    this->lot_atual= this->lot_atual - num;

    return this->lot_atual;
}
int onibus::transfere_passageiros(onibus *outro, int num){
    this->lot_atual -=num;
    outro->lot_atual +=num;

    return outro->lot_atual;
}
void onibus::imprimir_estado(){
    cout << this->placa << " (" << this->lot_atual << "/" << this->cap_max << ")" << endl;
}
