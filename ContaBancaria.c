#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.h"

Conta contas[MAX_SIZE];
int contadorClientes = 0;

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu() {
    int op = OP_NAO_SELECIONADA;

    printf("Banco\n");
    printf("%d - Inserir Nova Conta\n", OP_INSERIR);
    printf("%d - Alterar Conta\n", OP_ALTERAR);
    printf("%d - Listar Contas\n", OP_LISTAR);
    printf("%d - Depositar\n", OP_DEPOSITAR);
    printf("%d - Sacar\n", OP_SACAR);
    printf("%d - Imprimir Saldo\n", OP_IMPRIMIR);
    printf("%d - Saldo Geral\n", OP_SALDOGERAL);
    printf("%d - Sair\n", OP_SAIR);

    printf("Digite sua opcao\n");
    scanf("%d", &op);

    return op;
}

void inserir() {
    Conta *contaAtual = &contas[contadorClientes];

    printf("Digite os dados solicitados\n");

    contaAtual->numero = contadorClientes;

    printf("Nome do cliente: ");
    limpaBuffer();
    fgets(contaAtual->cliente, 51, stdin);

    printf("É uma conta especial? 1 - Sim / 2 - Nao\n");
    int especial;
    scanf("%d", &especial);
    if(especial == 1) contaAtual->especial = TRUE;
    else if(especial == 2) contaAtual->especial = FALSE;

    printf("Digite o saldo inicial da conta: \n");
    scanf("%lf", &contaAtual->saldo);

    printf("Cliente Adicionado - Dados Abaixo\n");
    printf("Numero: %d\n", contaAtual->numero);
    printf("Nome: %s\n", contaAtual->cliente);
    printf("Especial: %s\n", contaAtual->especial == TRUE ? "Sim" : "Nao");
    printf("Saldo Inicial: %.2lf\n", contaAtual->saldo);

    contadorClientes++;
}