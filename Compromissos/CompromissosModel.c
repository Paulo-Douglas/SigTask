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
        if(strcmp(compromise->id, id) == 0){
            fclose(fp);
            return compromise;
        }
    }
    fclose(fp);
    free(compromise);
    return NULL;

}


int update_date_compromise(const char **id, const char *new_value, const char *field, int length){
    FILE *fp = fopen("data/compromisers.txt", "r+");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

//     char line[512];
//     memset(line, 0, sizeof(line));
//     int found_id = 0;
//     long pos = 0;

//     while (fgets(line, sizeof(line), fp) != NULL) {
//         if (strstr(line, *id) != NULL) {
//             found_id = 1;
//         }

//         if (found_id && strstr(line, field) != NULL) {
//             char *field_pos = strstr(line, field);
//             if (field_pos == NULL) break;

//             pos = ftell(fp) - strlen(line) + (field_pos - line) + strlen(field);
//             fseek(fp, pos, SEEK_SET);

//             fprintf(fp, "%-*s", length, new_value);

//             fclose(fp);
//             return 1;
//         }
//     }
    fclose(fp);
    return 0;
}
