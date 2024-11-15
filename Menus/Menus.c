#include <stdio.h>
#include "Menus.h"
#include "../libs/utils.h"

char menuPrincipal(void) {
    char op;
    printf("\n");
    printf("---------------------------------------------------------------------\n");
    printf("|                                                                   |\n");
    printf("|           Sig-task: Sua genda de Tarefas e Compromissos           |\n");
    printf("|                                                                   |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|                                                                   |\n");
    printf("|                           [1] Usuários                            |\n");
    printf("|                           [2] Gerir Equipes                       |\n");
    printf("|                           [3] Tarefas                             |\n");
    printf("|                           [4] Compromissos                        |\n");
    printf("|                           [5] Sobre                               |\n");
    printf("|                           [0] Sair                                |\n");
    printf("|                                                                   |\n");
    printf("---------------------------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void menuSobre(void) {
    printf("\n");
    printf("---------------------------------------------------------------------\n");
    printf("|                                                                   |\n");
    printf("|                         Módulo Informações                        |\n");
    printf("|                                                                   |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|                                                                   |\n");
    printf("|            Universidade Federal do Rio Grande do Norte            |\n");
    printf("|                Centro de Ensino Superior do Seridó                |\n");
    printf("|              Departamento de Computação e Tecnologia              |\n");
    printf("|                    Sistemas de Informação - BSI                   |\n");
    printf("|                       Programação - DCT1106                       |\n");
    printf("|                 Agenda de Tarefas e Compromissos                  |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|                                                                   |\n");
    printf("|       Desenvolvedores:                                            |\n");
    printf("|                                                                   |\n");
    printf("|               Nome: André Leandro de Medeiros Araújo              |\n");
    printf("|               Email: andre.leandro.116@ufrn.edu.br                |\n");
    printf("|               GitHub: https://github.com/andrewszada              |\n");
    printf("|                                                                   |\n");
    printf("|                                                                   |\n");
    printf("|               Nome: Paulo Douglas Martins Dias                    |\n");
    printf("|               Email: paulo.martins.132@ufrn.edu.br                |\n");
    printf("|               GitHub: https://github.com/Paulo-Douglas            |\n");
    printf("|                                                                   |\n");
    printf("|               Nome: Anderson Gabriel Pereira Cruz                 |\n");
    printf("|               Email: gabriel.cruz.133@ufrn.edu.br                 |\n");
    printf("|               GitHub: https://github.com/anderson-cruz13          |\n");
    printf("---------------------------------------------------------------------\n");
    limpa_buffer();
    limpar_tela();
}