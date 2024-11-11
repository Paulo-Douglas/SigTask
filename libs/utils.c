#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>


void limpa_buffer(void) {
    int b;
    while((b = getchar()) != '\n' && b != EOF) {

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
	if (fp == NULL) return 0;

	for (int i = 0; data[i] != NULL ; i++){

		if (data[i + 1] == NULL){
			fprintf(fp, "%s\n", data[i]);
		} else {
			fprintf(fp, "%s,", data[i]);			
		}

	}

	fclose(fp);
	return 1;
}