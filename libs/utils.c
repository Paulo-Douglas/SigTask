#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "utils.h"


void limpa_buffer(void) {
    int b;
    while((b = getchar()) != '\n' && b != EOF) {

    }
}

void input(char **prompt){

	char line[256];
	scanf("%255[^\n]", line);
	int tam = strlen(line);
	*prompt = (char*) malloc(tam + 1);

	if (*prompt != NULL){
		strcpy(*prompt, line);
	}

}

void exibir_menssagem(char *menssagem) {
    printf("%s\n\n", menssagem);
    printf("Tecle <ENTER> para continuar...");
    getchar();
    limpa_buffer();
}

void limpar_tela(void) {
    system("clear || cls");
}

void create_path(const char *name_path) {
    struct stat path = {0};
    if(stat(name_path, &path) == -1){
        mkdir("data", 0700);
    }
}

int year_now(void) {
    // OpenAI. (2023). ChatGPT (modelo GPT-4)

    time_t t = time(NULL); // Tempo em segundos
    struct tm tm = *localtime(&t); // Tempo local
    int year = tm.tm_year + 1900; // Soma 1900 para obter o ano completo
    return year;
}

int save_file(const char *data[], char *file_name){
	FILE *fp = fopen(file_name, "a");
	if (fp == NULL) return FALSE;

	for (int i = 0; data[i] != NULL ; i++){

		if (data[i + 1] == NULL){
			fprintf(fp, "%s\n", data[i]);
		} else {
			fprintf(fp, "%s,", data[i]);			
		}

	}

	fclose(fp);
	return TRUE;
}

int move_to_struct(char *anything, char *cpf, char *name_anything) {
    File *read_file = malloc(sizeof(File));
    if (read_file == NULL) return FALSE;

    read_file->file = NULL;
    read_file->line_count = 0;

    char line[MAX_LINE_LENGTH];

    FILE * fp = fopen(name_anything, "r");    
    if (fp == NULL) return FALSE;                                                     

    while(fgets(line, MAX_LINE_LENGTH, fp) !=NULL) {
        read_file->line_count++;
        read_file->file = realloc(read_file->file, read_file->line_count * sizeof(char *));

        if (read_file->file == NULL){
            fclose(fp);
            return FALSE;
        }

        read_file->file[read_file->line_count - 1] = malloc(strlen(line) + 1);

        if (read_file->file[read_file->line_count - 1] == NULL){
            fclose(fp);
            return FALSE;
        }

        strcpy(read_file->file[read_file->line_count - 1], line);

    }

    add_user_to_register(read_file, anything, cpf);
    fclose(fp);
    free(read_file->file);
    free(read_file);
    return TRUE;

}

int add_user_to_register(File *read_file, char *anything, char *cpf) {

    for (int i = 0; i < read_file->line_count; i++){
        if(strstr(read_file->file[i], anything) == NULL) continue;
        else {
            read_file->file[i] = realloc(read_file->file[i], strlen(read_file->file[i]) + strlen(cpf) + 2);
            read_file->file[i][strlen(read_file->file[i]) - 1] = '\0';
            strcat(read_file->file[i], cpf);

            FILE *fp = fopen("anything.txt", "w");      // mudável
            if (fp == NULL) return FALSE;
            for (int i = 0; i < read_file->line_count; i++){
                read_file->file[i][strlen(read_file->file[i]) - 1] = '\0';
                fprintf(fp, "%s\n", read_file->file[i]);
            }
            fclose(fp);

            break;
        }

        free(read_file->file[i]);
    }

    return TRUE;
}