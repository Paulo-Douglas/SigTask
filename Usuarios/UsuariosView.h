#ifndef USUARIOVIEW_H
#define USUARIOVIEW_H

#define MAX_NAME 50
#define MAX_CPF 12
#define MAX_TEL 12

char menu_usuarios(void);
void cadastrar_usuarios(char *name, char *phone, char *cpf);
void exibir_dados_usuario(void);
void alterar_dados_usuario(void);
void excluir_usuario(void);
void dados_usuario(void);
void menu_alterar_usuario(void);
void show_error(const char *message);
void show_sucess(const char *message);

#endif