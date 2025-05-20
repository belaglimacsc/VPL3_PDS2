#include "Onibus.hpp"
#include "Empresa.hpp"
#include <string>
#include <iostream>

using namespace std;
void empresa::construtor(){
    this->num_onibus =0;
    for(int i=0;i< 20; i++){
        vet_ptr_onibus[i] = nullptr;
    }
}
onibus* empresa::adicionar_onibus(string placa, int cap_max){
    if(this->num_onibus < 20){
        onibus* novo_onibus = new onibus;
        for(int i=0;i < this->num_onibus; i++){
            if(this->vet_ptr_onibus[i]->placa == placa) return nullptr;
        }
        novo_onibus->construtor(placa, cap_max);
        this->vet_ptr_onibus[this->num_onibus] = novo_onibus;
        this->num_onibus++;
        if (!novo_onibus) {
            cout << "Erro ao alocar memória para o novo ônibus" << endl;
            return nullptr;
        }
        return novo_onibus;
    }
}

onibus* empresa::buscar_onibus(string placa){
    for(int i=0; i< this->num_onibus; i++){
        if(this->vet_ptr_onibus[i]->placa == placa){
            return this->vet_ptr_onibus[i];
        }
    }
    return nullptr;
}
void empresa::imprimir_estado(){
    for(int i=0; i< this->num_onibus;i++){
        this->vet_ptr_onibus[i]->imprimir_estado();
    }
}
