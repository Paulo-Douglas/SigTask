#ifndef COMPROMISSOSCONTROLLER_H
#define COMPROMISSOSCONTROLLER_H

#include "CompromissosModel.h"

void free_strcut_compromise(Compromisers *compromise);

int register_compromise(void);
int search_compromiser_to_user(const char* cpf);
int update_compromise(Compromisers *compromise, char *id);


#endif