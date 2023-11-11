#ifndef CONTABANCARIA_CONTABANCARIA_H
#define CONTABANCARIA_CONTABANCARIA_H

#define MAX_SIZE 10

enum {
    FALSE = 0,
    TRUE
};

enum {
    OP_NAO_SELECIONADA = 0,
    OP_INSERIR,
    OP_ALTERAR,
    OP_LISTAR,
    OP_DEPOSITAR,
    OP_SACAR,
    OP_IMPRIMIR,
    OP_SALDOGERAL,
    OP_SAIR
};

typedef int BOOLEAN;

typedef struct {
    int numero;
    char cliente[51];
    BOOLEAN especial;
    double saldo;
} Conta;

extern Conta contas[10];
extern int contadorClientes;

int menu();
void inserir();
void alterar(Conta *conta);
void procurar(Conta *conta);
void listar(Conta *conta);
void depositar(Conta *conta);
void sacar(Conta *conta);
void imprimir(Conta *conta);
void saldoGeral(Conta *conta);

#endif