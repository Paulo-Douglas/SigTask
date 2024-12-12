#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "CompromissosModel.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int insert_compromise(Compromisers *compromise){
    int id = get_next_id("data/compromisers.dat");
    if(id == 0) id = 1;

    snprintf(compromise->id, sizeof(compromise->id), "%d", id);

    create_path("data/");
    int result = FALSE;

    FILE *fp = fopen("data/compromisers.dat", "ab");
    if(fp == NULL) return result;

    if (fwrite(compromise, sizeof(Compromisers), 1, fp)) result = TRUE;

    fclose(fp);
    return result;
}

Compromisers * load_compromise(const char *id){
    FILE *fp = fopen("data/compromisers.dat", "rb");
    if(fp == NULL) return NULL;

    Compromisers *compromise = (Compromisers *)malloc(sizeof(Compromisers));
    while(fread(compromise, sizeof(Compromisers), 1, fp)){
        getchar();
        if(strcmp(compromise->id, id) == 0){
            fclose(fp);
            return compromise;
        }
    }
    fclose(fp);
    free(compromise);
    return NULL;

}

int update_compromise(Compromisers *compromise){
    FILE *fp = fopen("data/compromisers.dat", "rb+");
    if(fp == NULL) return FALSE;

    Compromisers compromiser;
    while(fread(&compromiser, sizeof(Compromisers), 1, fp)){
        if(strcmp(compromiser.id, compromise->id) == 0){
            fseek(fp, -sizeof(Compromisers), SEEK_CUR);
            fwrite(compromise, sizeof(Compromisers), 1, fp);
            fclose(fp);
            return TRUE;
        }
    }
    fclose(fp);
    return FALSE;
}
