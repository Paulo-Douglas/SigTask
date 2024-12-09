#ifndef COMPROMISSOSVIEW_H
#define COMPROMISSOSVIEW_H

#include "CompromissosController.h"

char menu_compromise(void);
void register_compromises(void);
void view_compromise(void);
void edit_compromise(void);
void delete_compromises(void);
void data_compromises(void);
void change_data_compromisses(void);
void display_data_compromises(Compromisers *compromise);

Compromisers initialize_compromisse(const char* title);

#endif