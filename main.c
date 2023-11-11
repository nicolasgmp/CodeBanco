#include "ContaBancaria.h"

int main(){
    int op = OP_NAO_SELECIONADA;

    while(op != OP_SAIR){
        op = menu();

        switch(op) {
            case OP_INSERIR:
                inserir();
                break;
        }
    }

    return 0;
}