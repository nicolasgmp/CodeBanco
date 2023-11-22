#include "ContaBancaria.h"

size_t tamanho = MAX_SIZE;
Conta *contaAtual = NULL;
Conta *contas = NULL;
Conta *encontrado = NULL;
int contadorClientes = 0;
int especial = -1;

/**
 * Função: limpaBuffer
 *
 * Esta função limpa o buffer de entrada, removendo todos os caracteres não lidos até o final da linha.
 * Semelhante ao funcionamento do fflush(stdin) ou __fpurge(stdin), porém é funcional em qualquer SO.
 */
void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

/**
 * Função: menu
 *
 * A função implementa um menu de opções para guiar o usuário na utilização do sistema bancário.
 * Exibe opções para inserir, alterar, listar, depositar, sacar, imprimir, saldo geral e sair.
 * Solicita a opção ao usuário.
 *
 * @return A opção escolhida pelo usuário
 */
int menu()
{
    int op = OP_NAO_SELECIONADA;

    printf("\nBanco\n");
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

/**
 * Função: inserir
 *
 * Esta função solicita os dados para a inserção de uma nova conta no sistema. Ela faz algumas verifições básicas como não deixar que um nome com menos de 3 caracteres seja inserido, além de garantir que o status de especial seja 1 para "SIM" ou 2 para "NÃO". Após isso, os dados cadastrados são mostrados.
 *
 * @param l_contas Ponteiro para a lista de contas existente.
 */
void inserir(Conta *l_contas)
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
}

/**
 * Função: alterar
 *
 * Implementa a possibilidade de alterar os dados de um cliente já cadastrado no sistema. Porém, apenas nome e status de especial podem ser alterados. Ela faz algumas verifições básicas como não deixar que um nome com menos de 3 caracteres seja inserido, além de garantir que o status de especial seja 1 para "SIM" ou 2 para "NÃO". Após a alteração, o cliente atualizado é mostrado.
 *
 * @param conta Ponteiro para a conta que será alterada
 */
void alterar(Conta *conta)
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

/**
 * Função: listar
 *
 * Verifica se a lista passada como parâmetro não é vazia. Se não estiver vazia, um loop for de 0 até o total de contas cadastradas é realizado exibindo os detalhes de cada um dos clientes caso não sejam especiais, incluindo número de conta, nome, status e saldo.
 *
 * @param l_contas Ponteiro para a lista de contas existentes.
 * @param totalContas Número inteiro da quantidade de contas cadastradas.
 */
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
        if (contaAtual->especial == FALSE)
        {
            printf("Numero: %d\n", contaAtual->numero);
            printf("Nome: %s", contaAtual->cliente);
            printf("Especial: %s\n", "Nao");
            printf("Saldo: %.2lf\n\n", contaAtual->saldo);
        }
    }
}

/**
 * Função: depositar
 *
 * A função verifica se a lista de clientes está vazia. Se não estiver, verifica se a conta passada como parâmetro existe. Se existir, o valor passado como parâmetro é somado ao saldo da conta e uma mensagem de sucesso é exibida.
 *
 * @param conta Ponteiro para a conta que o valor será depositado.
 * @param valor A quantia a ser depositada na conta.
 */
void depositar(Conta *conta, double valor)
{
    if (isEmpty())
    {
        printf("\nLista de Clientes vazia\n");
        return;
    }

    if (conta)
    {
        conta->saldo += valor;
        printf("\nDeposito efetuado com sucesso\n\n");
        return;
    }
}

/**
 * Função sacar
 *
 * A função verifica se a lista de clientes está vazia. Se não estiver, verifica se a conta passada por parâmetro existe. Se existir, verifica se o saldo da conta é menor que o valor passado por parâmetro, caso verdadeiro, a quantia é retirada do saldo da conta em questão.
 *
 * @param conta Ponteiro para a conta na qual o valor será sacado.
 * @param valor A quantia a ser retirada da conta.
 */
void sacar(Conta *conta, double valor)
{
    if (isEmpty())
    {
        printf("\nLista de Clientes vazia\n");
        return;
    }

    if (conta)
    {
        if (conta->saldo < valor)
        {
            printf("\nSaldo insuficiente!\n");
            return;
        }
        conta->saldo -= valor;
        printf("\nSaque efetuado com sucesso\n\n");
        return;
    }
}

/**
 * Função: imprimir
 *
 * A função verifica se a lista de clientes está vazia. Se não estiver, verifica se a conta passada por parâmetro existe. Se existir, os detalhes do cliente em questão são exibidos na tela.
 *
 * @param conta Ponteiro para a conta a ser impressa.
 */
void imprimir(Conta *conta)
{
    if (isEmpty())
    {
        printf("\nLista de clientes vazia\n");
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

/**
 * Função: saldoGeral
 *
 * A função verifica se a lista de clientes está vazia. Se não estiver, itera sobre todas as contas presentes no sistema e retorna o saldo somado delas.
 *
 * @param l_contas Ponteiro para a lista de contas
 * @param totalContas Inteiro do total de contas cadastradas.
 *
 * @return O saldo somado de todas as contas.
 */
double saldoGeral(Conta *l_contas, int totalContas)
{
    if (isEmpty())
    {
        printf("\nLista de clientes vazia\n");
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

/**
 * Função: buscar
 *
 * Itera sobre todas as contas cadastradas, caso o numero da conta atual seja igual ao solicitado, retorna a conta.
 *
 * @param l_contas Ponteiro para a lista de contas cadastradas.
 * @param totalContas Inteiro do número total de contas.
 * @param numero Inteiro referente ao numero da conta buscada.
 *
 * @return Caso a conta seja encontrada, retorna-a. Caso contrário, é retornado NULL.
 */
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

/**
 * Função: inicializar
 *
 * Inicializa a lista de contas de acordo com o número especificado de contas (definido por "tamanho") usando a função "malloc()" que utiliza "sizeof" para encontrar o tamanho exato de uma "Conta".
 */
void inicializar()
{
    contas = malloc(tamanho * sizeof(Conta));
}

/**
 * Função: finalizar
 *
 * Libera a memória alocada após o fim do uso do programa.
 */
void finalizar()
{
    free(contas);
}

/**
 * Função: expandir
 *
 * Calcula um novo tamanho para a lista multiplicando o tamanho atual por 2. A função aloca um novo bloco de memória com o novo tamanho e copia os dados da lista original para a nova. Se a alocação falhar, libera a memória da lista original, exibe uma mensagem de erro e encerra o programa com código "-1". Após a cópia bem-sucedida, libera a memória da lista original e atualiza o ponteiro "contas" para apontar para o novo bloco de memória.
 */
void expandir()
{
    size_t newTamanho = (size_t)tamanho * 2;
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

/**
 * Função: isEmpty
 *
 * Verifica se o total de contas cadastradas é igual 0.
 *
 * @return Retorn "TRUE" caso o número de contas seja igual a 0. Caso contrário, retorna "FALSE".
 */
BOOLEAN isEmpty()
{
    return contadorClientes == 0;
}
/**
 * Função: isFull
 *
 * Verifica se o total de contas cadastradas é igual ao tamanho máximo.
 *
 * @return Retorn "TRUE" caso o número de contas seja igual ao máximo. Caso contrário, retorna "FALSE".
 */
BOOLEAN isFull()
{
    return contadorClientes == MAX_SIZE;
}