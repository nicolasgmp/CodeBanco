#include "ContaBancaria.h"

size_t tamanho = MAX_SIZE;
Conta *contaAtual = NULL;
Conta *contas = NULL;
int contadorClientes = 0;
int especial = -1;

void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int menu()
{
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

void inserir()
{
    contaAtual = &contas[contadorClientes];

    printf("Digite os dados solicitados\n");

    contaAtual->numero = contadorClientes;

    limpaBuffer();
    do
    {
        printf("Nome do cliente: ");
        fgets(contaAtual->cliente, 51, stdin);
    } while (strlen(contaAtual->cliente) <= 3);

    do
    {
        printf("É uma conta especial? 1 - Sim / 2 - Nao\n");
        scanf("%d", &especial);
    } while (especial != 1 && especial != 2);
    contaAtual->especial = especial == 1 ? TRUE : FALSE;

    printf("Digite o saldo inicial da conta: \n");
    scanf("%lf", &contaAtual->saldo);

    printf("Cliente Adicionado - Dados Abaixo\n");
    printf("Numero: %d\n", contaAtual->numero);
    printf("Nome: %s", contaAtual->cliente);
    printf("Especial: %s\n", contaAtual->especial == TRUE ? "Sim" : "Nao");
    printf("Saldo Inicial: %.2lf\n\n", contaAtual->saldo);

    contadorClientes++;
}

void alterar(Conta *conta, int numero)
{
    limpaBuffer();
    do
    {
        printf("Digite o novo nome: ");
        fgets(conta->cliente, 51, stdin);
    } while (strlen(conta->cliente) <= 3);

    do
    {
        printf("Especial? 1 - Sim / 2 - Nao\n");
        scanf("%d", &especial);
    } while (especial != 1 && especial != 2);
    conta->especial = especial == 1 ? TRUE : FALSE;

    printf("Dados Alterados\n");
    printf("Numero: %d\n", conta->numero);
    printf("Nome: %s", conta->cliente);
    printf("Especial: %s\n", conta->especial == TRUE ? "Sim" : "Nao");
    printf("Saldo Inicial: %.2lf\n\n", conta->saldo);
}

Conta *buscar(Conta *conta, int numero)
{

    for (int i = 0; i < contadorClientes; i++)
    {
        contaAtual = &conta[i];
        if (contaAtual->numero == numero)
            return contaAtual;
    }

    return NULL;
}

void inicializar()
{
    contas = malloc(tamanho * sizeof(Conta));
}

void finalizar()
{
    free(contas);
}

void expandir()
{
    size_t newTamanho = tamanho * 1.5;
    Conta *p;

    p = malloc(newTamanho * sizeof(Conta));

    if (!p)
        exit(-1);

    for (int i = 0; i < tamanho; i++)
    {
        contaAtual = &contas[i];
        p[i].numero = contaAtual->numero;
        strcpy(p[i].cliente, contaAtual->cliente);
        p[i].especial = contaAtual->especial;
        p[i].saldo = contaAtual->saldo;
    }

    free(contas);
    contas = p;
    tamanho = newTamanho;
}

BOOLEAN isEmpty()
{
    return contadorClientes == 0;
}