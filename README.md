<h1 align="center">Sistema de Contas Bancárias em C</h1>
<h2 align="center"> Code Banco</h2>
<p align="center">
  <a href="https://github.com/magrininicolas/placesAPIMVC/blob/main/LICENSE">
    <img src="https://img.shields.io/npm/l/react" alt="NPM License" />
 </a>
  <a href="https://www.linkedin.com/in/nicolasgmpereira">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
  </a>
</p>

- [English README version](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/READMEen.md) - :warning: **Under construction**

## Vídeos Explicativos
- [Parte 1](https://www.youtube.com/watch?v=LC_gW7JZM8w)
- [Parte 2](https://www.youtube.com/watch?v=NEqkzazQ5JM)

## Equipe

```
Nicolas Gustavo Magrini Pereira
Leonardo Morari dos Santos
Carlos Henrique Nóbrega da Silva
Jesua Isaque Calefi da Silva
```

Sistema para controle de contas bancárias feito com base em um dos temas propostos [neste trabalho](https://maromo71.notion.site/Trabalho-LP-Manh-e-Noite-94d594d7176f420cae42cbd910bd3716) de conclusão da disciplina de Linguagem de Programação no curso de Análise e Desenvolvimento de Sistemas da Fatec Mogi Mirim.

## Ferramentas Utilizadas

- [![C](https://skillicons.dev/icons?i=c) - Linguagem C](https://en.cppreference.com/w/c)
- [![Visual Studio Code](https://skillicons.dev/icons?i=vscode) - VSCode](https://code.visualstudio.com)
- [![VIM](https://skillicons.dev/icons?i=vim) - VIM plugin no VSCode](https://github.com/vim/vim)

# Como Executar

## Localmente

- Você deve ter o gcc configurado no seu sistema operacional
- Abra o terminal
- Clone o repósitorio do git
- Vá até onde o repositório foi clonado

```
cd ./pasta
```

- Insira o seguinte comando no terminal

```
gcc main.c ContaBancaria.c -o nome-programa -lm
```

- Rode

```
./nome-programa (Linux)

nome-programa.exe (Windows)
```

- Se tudo estiver correto, o seu terminal deverá apresentar o seguinte

<p align="center">
  <img src="https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/print_1.png" alt="Terminal">
</p>

- O programa está pronto para uso

## Usando Docker

- Clone o repositório do git
- Verifique se o arquivo "Dockerfile" está presente. Se não estiver, crie-o e adicione o seguinte

```
FROM gcc:latest
WORKDIR $PWD
COPY ContaBancaria.c ./
COPY ContaBancaria.h ./
COPY main.c ./
RUN gcc ContaBancaria.c main.c -o ContaBancaria -lm
CMD ["./ContaBancaria"]
```

- Faça o build da imagem

```
docker build -t nome-imagem .
```

- Rode o container

```
docker run --name nome-prog -it nome-imagem
```

- Para rodar o programa novamente

```
docker start -ai nome-prog
```

## Usando CLION

- Clone o repositório do git
- Crie um novo projeto na pasta onde o repositório foi clonado (Selecione a versão 17 do C)
- O "CMakeLists.txt" deve conter o seguinte

```
cmake_minimum_required(VERSION 3.26)
project(Contas_Bancarias_C C)

set(CMAKE_C_STANDARD 17)

add_executable(Contas_Bancarias_C main.c ContaBancaria.c ContaBancaria.h)
```

- Rode utilizando a IDE

# Funções e Estruturas

- Boolean

  ![boolean](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/boolean_print.png)

  Uma estrutura é definida para que seja possível o retorno de valores booleanos e não apenas inteiros como 0 e 1. Tornando mais fácil a interpretação do funcionamento das condições.

- Conta
  ![conta](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/conta_print.png)
  Esta estrutura define quais atributos as contas terão, são eles: o número da conta do cliente, o nome do cliente, se ele é especial ou não (seus dados não serão públicos) e o saldo presente na conta.

- Menu
  ![menu](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/menu_print.png)
  Um menu interativo é apresentado para que o usuário possa escolher qual opção ele irá querer realizar no sistema, o retorno da função é a opção escolhida.

- Inserir
  ![inserir](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/inserir_print.png)
  A função recebe como parâmetro um ponteiro para um array do tipo Conta. Após isso, são solicitados todos os dados do cliente que será cadastrado no sistema.

- Alterar
  ![alterar](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/alterar_print.png)
  Alterar recebe um ponteiro para a conta a ser modificada, portanto precisa ser uma conta já previamente encontrada no sistema com a função buscar (explicada mais abaixo). Após isso, são solicitados os dados que poderão ser modificados.

- Listar
  ![listar](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/listar_print.png)
  Listar recebe um ponteiro para um array do tipo Conta e o número total de contas cadastradas no sistema. Após isso, serão exibidos os dados de todos os clientes não especiais do sistema.

- Depositar
  ![depositar](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/depositar_print.png)
  Depositar recebe um ponteiro para a conta, encontrada por "buscar()", que receberá o depósito e o valor a ser depositado.

- Sacar
  ![sacar](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/sacar_print.png)
  Sacar recebe um ponteiro para a conta, encontrada por "buscar()", a qual será realizada o saque e o valor a ser sacado. Caso o valor seja maior do que o saldo presente na conta, uma mensagem será exibida e a função parará.

- Imprimir
  ![imprimir](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/imprimir_print.png)
  Imprimir recebe um ponteiro para a conta que será exibida na tela, como é necessário saber o número da conta, clientes especiais poderão ser exibidos.

- Saldo Geral
  ![saldoGeral](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/saldoGeral_print.png)
  Saldo Geral recebe um ponteiro para um array de Contas e o número total de contas. Após isso, o valor somado do saldo de todas as contas presentes no sistema será exibido.

- Buscar
  ![buscar](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/buscar_print.png)
  Buscar recebe um ponteiro para um array de Contas, o número total de contas e o número da conta a ser buscada. Se a conta for encontrada, ela será retornada. Caso contrário, será retornado um valor nulo.

- Funções para Alocação Dinâmica
  ![alocacaoDinamica](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/alocacao_Dinamica_print.png)

  - Inicializar aloca a memória inicial necessária para o funcionamento do sistema de acordo com o tamanho máximo inicial e o tamanho ocupado por uma estrutura do tipo Conta. Ela é executada automaticamente antes de qualquer função no sistema.
  - Finalizar desaloca/libera a memória alocada para o array de contas. Ela é a última coisa a ser executada quando o sistema é fechado.
  - Expandir realoca a memória do array de contas quando o tamanho máximo é atigindo. Todos os dados do array de contas são passados para um array auxiliar, a memória do array de contas é liberada e o array auxiliar vira o novo array de contas.

- Funções para checagem de tamanho
  ![tamanho](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/verificacaoTamanho_print.png)
  - isEmpty verifica se o número de clientes é igual a 0, tornando o array de contas vazio. Retorna TRUE ou FALSE.
  - isFull verifica se o número de clientes é igual ao tamanho máximo atual. Retorna TRUE ou FALSE.
