#ifndef TAREFASVIEW_H
#define TAREFASVIEW_H

#include "TarefasModel.h"

char menu_tarefas(void);
void cadastrar_tarefas(void);
void exibir_tarefas(void);
void editar_tarefas(void);
void excluir_tarefas(void);
void dados_tarefas(Tasks *task);
void alterar_dados_tarefas(void);

#endif