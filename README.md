<h1 align="center">Sistema de Contas Bancárias em C</h1>
<p align="center">
  <a href="https://github.com/magrininicolas/placesAPIMVC/blob/main/LICENSE">
    <img src="https://img.shields.io/npm/l/react" alt="NPM License" />
 </a>
  <a href="https://www.linkedin.com/in/nicolasgmpereira">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
  </a>
</p>

- [English README version](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/READMEen.md)

- Equipe
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
- [![VIM](https://skillicons.dev/icons?i=vim) - VIM](https://github.com/vim/vim)

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

# Funções

- Menu
![menu](https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/menu_print.png)
Esta função apresenta um menu interativo para que o usuário possa escolher qual opção ele irá querer realizar no sistema, o retorno da função é a opção escolhida.