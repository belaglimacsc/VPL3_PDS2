#include <iostream>
#include <string>
#include "Onibus.hpp"
#include "Empresa.hpp"
using namespace std;

int main(){
    char c;
    string placa1, placa2;
    int p_sub, cap_max, p_des, p_transf;

    empresa e;
    e.construtor();
    while((cin>>c) && c !='F'){
        if (c == 'C'){
            cin >> placa1 >> cap_max;
            
            onibus* novo_onibus = e.adicionar_onibus(placa1, cap_max);
            if(novo_onibus){
                cout << "novo onibus cadastrado" << endl;
            }
            else cout << "ERRO : onibus repetido" << endl;
        }
        if (c == 'S'){
            cin >> placa1 >> p_sub;

            onibus* onibus_encontrado = e.buscar_onibus(placa1);
            if(onibus_encontrado){
                if(onibus_encontrado->lot_atual + (p_sub) > onibus_encontrado->cap_max){
                    cout << "ERRO : onibus lotado"<< endl;
                }
                else{
                    onibus_encontrado->subir_passageiros(p_sub);
                    cout<< "passageiros subiram com sucesso" << endl;
                } 
            }
            else cout << "ERRO : onibus inexistente" << endl;
        }
        if(c == 'D'){
            cin >> placa1 >> p_des;

            onibus* onibus_encontrado = e.buscar_onibus(placa1);
            if(onibus_encontrado){
                if(onibus_encontrado->lot_atual - (p_des) < 0){
                    cout << "ERRO : faltam passageiros" << endl;
                    //cout << "num atual de passageiros:" << onibus_encontrado->lot_atual << endl;
                    //cout << "num atual de passageiros: AAA" << onibus_encontrado->lot_atual << endl;
                }
                else{
                    onibus_encontrado->descer_passageiros(p_des);
                     cout << "passageiros desceram com sucesso" << endl;
                     //cout << "num atual de passageiros: BBB" << onibus_encontrado->lot_atual << endl;
                }
            }
            else cout << "ERRO : onibus inexistente" << endl;
        }
        if(c =='T'){
            cin >> placa1 >> placa2 >> p_transf;
            onibus* onibus1 = e.buscar_onibus(placa1);
            onibus* onibus2 = e.buscar_onibus(placa2);
            if(onibus1 && onibus2){
                if (onibus1->lot_atual - p_transf < 0 || onibus2->lot_atual +p_transf > onibus2->cap_max){
                    cout << "ERRO : transferencia cancelada" << endl;
                }
                else {
                    onibus1->transfere_passageiros(onibus2, p_transf);
                    cout << "transferencia de passageiros efetuada" << endl;
                }
            }
            else cout << "ERRO : onibus inexistente" << endl;
        }
        if(c=='I'){
            e.imprimir_estado();
        }
    }

    return 0;
}
