#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CompromissosModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int insert_compromise(Compromisers *compromise){
    FILE *fp = fopen("data/compromisers.txt", "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%-3d:%-50s[%-100s]%-10s-%-10s(%s)%s#1\n",
        compromise->team_id,
        compromise->title,
        compromise->description,
        compromise->start_date,
        compromise->end_date,
        compromise->time,
        compromise->priority);

    fclose(fp);
    return TRUE;
}


int load_compromise(const char *cpf){

    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    fclose(fp);
    return FALSE;
}
