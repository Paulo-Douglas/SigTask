#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CompromissosModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int load_compromise(const char *cpf){

    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    fclose(fp);
    return FALSE;
}
