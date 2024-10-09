<h2 align="center">SigTask - Agenda de Tarefas e Compromissos</h2>

<p align="center">
  <a href="#introdução">Introdução</a> |
  <a href="#sobre-o-projeto">Sobre o Projeto</a> |
  <a href="#requisitos">Requisitos</a> |
  <a href="#compilação-e-execução">Compilação e Execução</a>
</p>

## Introdução

Este é um projeto simples desenvolvido para ajudar usuários a gerenciar suas tarefas e compromissos de forma eficiente. 
Ele permite que os usuários tenham total controle sobre sua agenda, organizando atividades e prazos de maneira prática. 
Além disso, é uma ferramenta útil para gerentes de projetos, facilitando o gerenciamento de tarefas e a organização das equipes.

## Sobre o Projeto

Este projeto está sendo desenvolvido como parte da atividade avaliativa da disciplina Programação - DCT1106, do segundo período do curso de Bacharelado em Sistemas de Informação, oferecido pela Universidade Federal do Rio Grande do Norte (UFRN). 
O objetivo é aplicar os conceitos aprendidos em sala de aula, promovendo o desenvolvimento de habilidades práticas em programação.

> [!WARNING]\
> Este **NÃO** é um programa comercial. Os desenvolvedores não se responsabilizam por quaisquer danos.

## Requisitos

Para a execução deste projeto, é necessário um ambiente básico com terminal e ferramentas de compilação para C. Veja os requisitos abaixo:

#### 3.1 Sistema Operacional

O projeto é compatível com Windows, Linux e macOS, desde que todas as dependências estejam corretamente instaladas e configuradas.

> [!NOTE]\
Se você estiver usando um sistema operacional diferente do Linux, podem ocorrer erros. Recomenda-se utilizar Linux para garantir melhor funcionamento e compatibilidade do projeto.

----

#### 3.2 Instalação do Build-Essential

O pacote ```build-essential``` inclui o compilador GCC e o Make, que são necessários para compilar o código C no **Linux**.

- No Ubuntu ou Debian:
  
```matlab
sudo apt update
sudo apt install build-essential
```

- Verificando a Instalação:
  
```matlab
gcc --version
make --version
```

## Compilação e Execução

Passo a passo de como compilar e executar o programa:

#### 4.1 Clone o Projeto

Faça o clone do projeto usando o link abaixo:
```matlab
https://github.com/Paulo-Douglas/SigTask.git
```

-----

#### 4.2 Usando o Makefile

1. Abra o terminal e navegue até o diretório onde o projeto foi clonado.
2. Use os comandos ```make``` para compilar e executar o programa. Abaixo está uma tabela com os comandos disponíveis e suas respectivas funções:

| Comandos | Funções | Arquivos Gerados |
-----------|---------|------------------|
| make all | Compila os arquivos ```.c```, cria os arquivos objeto e os vincula em um arquivo executável | Arquivos objetos ```.o``` e o executável ```main```|
| make run | Limpa o terminal e executa o arquivo ```main``` gerado pela regra ```all``` | Nenhum arquivo será gerado |
| make clean | Remove todos os arquivos objetos ```.o``` e os execultavies | Nenhum arquivo será gerado |

-----

#### 4.3 Outro Modo de Compilar e Executar

- Execute os comando no diretório do projeto:

```matlab
gcc -Wall -c */*.c
```
```matlab
gcc -Wall -c main.c
```
```matlab
gcc -o main *o
```
```matlab
./main
```