#include "ContaBancaria.h"

int main()
{
    inicializar();

    int op = OP_NAO_SELECIONADA;
    int num;

    while (op != OP_SAIR)
    {
        op = menu();

        switch (op)
        {
        case OP_INSERIR:
            inserir();
            break;
        case OP_ALTERAR:
            printf("Digite o número da conta: ");
            scanf("%d", &num);
            Conta *encontrado = buscar(contas, num);

            if(!encontrado)
            {
                printf("Cliente não encontrado");
                break;
            }
            alterar(encontrado, num);
            break;
        }
    }

    finalizar();

    return 0;
}