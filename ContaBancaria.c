#include "ContaBancaria.h"

size_t tamanho = MAX_SIZE;
Conta *contaAtual = NULL;
Conta *contas = NULL;
Conta *encontrado = NULL;
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
    printf("%d - Imprimir Cliente\n", OP_IMPRIMIR);
    printf("%d - Saldo Geral\n", OP_SALDOGERAL);
    printf("%d - Sair\n", OP_SAIR);

    printf("Digite sua opcao\n");
    scanf("%d", &op);

    return op;
}

int inserir(Conta *l_contas)
{
    contaAtual = &l_contas[contadorClientes];

    printf("Digite os dados solicitados\n");

    contaAtual->numero = contadorClientes + 1;

    limpaBuffer();
    do
    {
        printf("Nome do cliente: ");
        fgets(contaAtual->cliente, 51, stdin);
    } while (strlen(contaAtual->cliente) <= 3);

    do
    {
        printf("Eh uma conta especial? 1 - Sim / 2 - Nao\n");
        scanf("%d", &especial);
    } while (especial != 1 && especial != 2);
    contaAtual->especial = especial == 1 ? TRUE : FALSE;

    printf("Digite o saldo inicial da conta: \n");
    scanf("%lf", &contaAtual->saldo);

    printf("\nCliente Adicionado - Dados Abaixo\n");
    printf("Numero: %d\n", contaAtual->numero);
    printf("Nome: %s", contaAtual->cliente);
    printf("Especial: %s\n", contaAtual->especial == TRUE ? "Sim" : "Nao");
    printf("Saldo Inicial: %.2lf\n\n", contaAtual->saldo);

    contadorClientes++;

    return TRUE;
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

    printf("\nCliente Atualizado - Dados Abaixo\n");
    printf("Numero: %d\n", conta->numero);
    printf("Nome: %s", conta->cliente);
    printf("Especial: %s\n", conta->especial == TRUE ? "Sim" : "Nao");
    printf("Saldo: %.2lf\n\n", conta->saldo);
}

void listar(Conta *l_contas, int totalContas)
{
    if (isEmpty())
    {
        printf("Lista de Clientes vazia\n\n");
        return;
    }

    printf("\nClientes\n");
    for (int i = 0; i < totalContas; i++)
    {
        contaAtual = &l_contas[i];
        printf("Numero: %d\n", contaAtual->numero);
        printf("Nome: %s", contaAtual->cliente);
        printf("Especial: %s\n", contaAtual->especial == TRUE ? "Sim" : "Nao");
        printf("Saldo: %.2lf\n\n", contaAtual->saldo);
    }
}

void depositar(Conta *conta, double valor)
{
    if (isEmpty())
    {
        printf("Lista de Clientes vazia\n");
        return;
    }

    if (conta)
    {
        conta->saldo += valor;
        printf("\nDeposito efetuado com sucesso\n\n");
        return;
    }
}

void sacar(Conta *conta, double valor)
{
    if (isEmpty())
    {
        printf("Lista de Clientes vazia\n");
        return;
    }

    if (conta)
    {
        if (conta->saldo < valor)
        {
            printf("Saldo insuficiente!\n");
            return;
        }
        conta->saldo -= valor;
        printf("\nSaque efetuado com sucesso\n\n");
        return;
    }
}

void imprimir(Conta *conta)
{
    if (isEmpty())
    {
        printf("Lista de clientes vazia\n");
        return;
    }

    if (conta)
    {
        printf("\nCliente encontrado - Dados Abaixo\n");
        printf("Numero: %d\n", conta->numero);
        printf("Nome: %s", conta->cliente);
        printf("Especial: %s\n", conta->especial == TRUE ? "Sim" : "Nao");
        printf("Saldo: %.2lf\n\n", conta->saldo);
    }
}

double saldoGeral(Conta *l_contas, int totalContas)
{
    if (isEmpty())
    {
        printf("Lista de clientes vazia\n");
        return 0.0;
    }

    double saldo = 0;
    for (int i = 0; i < totalContas; i++)
    {
        contaAtual = &l_contas[i];
        saldo += contaAtual->saldo;
    }
    return saldo;
}

Conta *buscar(Conta *l_contas, int totalContas, int numero)
{

    for (int i = 0; i < totalContas; i++)
    {
        contaAtual = &l_contas[i];
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
    size_t newTamanho = (size_t)tamanho * 1.5;
    Conta *p = malloc(newTamanho * sizeof(Conta));

    if (!p)
    {
        free(contas);
        exit(-1);
    }

    for (int i = 0; i < contadorClientes; i++)
    {
        p[i].numero = contas[i].numero;
        strcpy(p[i].cliente, contas[i].cliente);
        p[i].especial = contas[i].especial;
        p[i].saldo = contas[i].saldo;
    }

    free(contas);
    contas = p;
    tamanho = newTamanho;
}

BOOLEAN isEmpty()
{
    return contadorClientes == 0;
}

BOOLEAN isFull()
{
    return contadorClientes == MAX_SIZE;
}