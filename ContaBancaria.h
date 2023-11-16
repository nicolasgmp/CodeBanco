#ifndef CONTABANCARIA_CONTABANCARIA_H
#define CONTABANCARIA_CONTABANCARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

enum
{
    FALSE = 0,
    TRUE
};

enum
{
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

typedef struct
{
    int numero;
    char cliente[51];
    BOOLEAN especial;
    double saldo;
} Conta;

extern int contadorClientes;
extern Conta *contas;
extern Conta *contaAtual;
extern int especial;

int menu();
void inserir();
void alterar(Conta *conta, int numero);
Conta *buscar(Conta *conta, int numero);
void listar();
void depositar();
void sacar();
void imprimir();
void saldoGeral();
void inicializar();
void finalizar();
void expandir();
BOOLEAN isEmpty();

#endif