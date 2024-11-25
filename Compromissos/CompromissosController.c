#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CompromissosController.h"
#include "CompromissosView.h"
#include "CompromissosModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"



int register_compromise(void){
    limpa_buffer();
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|                              REGISTRO DE COMPROMISSOS                             |\n");
    return FALSE;
}

int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}

int upload_data_compromiser(const char* cpf){
    return load_compromise(cpf);
}

