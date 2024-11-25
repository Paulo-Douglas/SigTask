#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#include "utils.h"

void delete_spaces(char *str) {
    while (isspace((unsigned char)*str)) str++;
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

void limpa_buffer(void) {
    int b;
    while((b = getchar()) != '\n' && b != EOF);
}

void enter(void) {
    printf("| Tecle <ENTER> para continuar...");
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_next_id(const char *name_of_file) {
    FILE *arquivo = fopen(name_of_file, "r");
    if (arquivo == NULL) {
        return 1;
    }

    char line[300];
    char last_line[300] = "";

    while (fgets(line, sizeof(line), arquivo) != NULL) {
        strcpy(last_line, line);
    }

    fclose(arquivo);

    if (strlen(last_line) == 0) {
        return 1;
    }

    char *comma_pos = strchr(last_line, ',');
    if (comma_pos == NULL) {
        return 1;
    }

    return atoi(comma_pos + 1) + 1;
}