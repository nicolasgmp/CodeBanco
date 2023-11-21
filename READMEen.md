<h1 align="center">Bank Account System C</h1>
<p align="center">
  <a href="https://github.com/magrininicolas/placesAPIMVC/blob/main/LICENSE">
    <img src="https://img.shields.io/npm/l/react" alt="NPM License" />
 </a>
  <a href="https://www.linkedin.com/in/nicolasgmpereira">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
  </a>
</p>

- Team
```
Nicolas Gustavo Magrini Pereira
Leonardo Morari dos Santos
Carlos Henrique Nóbrega da Silva
Jesua Isaque Calefi da Silva
```

Program designed to simulate a bank account system that was made with one of the proposed themes in [this link](https://maromo71.notion.site/maromo71/Trabalho-LP-Manh-e-Noite-94d594d7176f420cae42cbd910bd3716). This system was created as a final project for the Language Programming class in the System Analysis and Development course at Fatec Mogi Mirim.

## Technologies Used
- [![C](https://skillicons.dev/icons?i=c) - Linguagem C](https://en.cppreference.com/w/c)
- [![Visual Studio Code](https://skillicons.dev/icons?i=vscode) - VSCode](https://code.visualstudio.com)
- [![VIM](https://skillicons.dev/icons?i=vim) - VIM](https://github.com/vim/vim)

# How to Execute

## Locally

- Make sure that you have the gcc configured on your OS
- Open the terminal
- Clone git repository
- Go to the folder destination

```
./folder
```

- Run this command on the terminal

```
gcc main.c ContaBancaria.c -o program-name -lm
```

- Run

```
./program-name (Linux)

program-name.exe (Windows)
```

- If everything is right, your terminal should be like this

<p align="center">
  <img src="https://github.com/magrininicolas/Contas-Bancarias-C/blob/main/imgs/print_1.png" alt="Terminal">
</p>

## Using Docker

- Open the terminal
- Clone git repository
- Verify if "Dockerfile" is on your folder. If not, create and type below

```
FROM gcc:latest
WORKDIR $PWD
COPY ContaBancaria.c ./
COPY ContaBancaria.h ./
COPY main.c ./
RUN gcc ContaBancaria.c main.c -o ContaBancaria -lm
CMD ["./ContaBancaria"]
```

- Build the image

```
docker build -t image-name .
```

- Run the container

```
docker run --name program-name -it image-name
```

- To run again

```
docker start -ai program-name
```

## Using CLION

- Clone git repository
- Create a new project on the folder that you have cloned the repository (Select C17)
- The "CMakeLists.txt" must be like below

```
cmake_minimum_required(VERSION 3.26)
project(Contas_Bancarias_C C)

set(CMAKE_C_STANDARD 17)

add_executable(Contas_Bancarias_C main.c ContaBancaria.c ContaBancaria.h)
```

- Run