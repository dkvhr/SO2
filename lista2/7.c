// exercicio 7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <caminho_base>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *caminho_base = argv[1];

    time_t t = time(NULL);
    // Converte o tempo para uma estrutura tm (que contém ano, mês, dia, etc.).
    struct tm tm = *localtime(&t);
    char data_string[11];

    // YYYY-MM-DD.
    sprintf(data_string, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    char caminho_completo[256];
    snprintf(caminho_completo, 256, "%s/%s", caminho_base, data_string);

    if (mkdir(caminho_completo, 0755) == 0) {
        printf("Diretório '%s' criado com sucesso.\n", caminho_completo);
    } else {
        perror("Erro ao criar o diretório");
    }

    return EXIT_SUCCESS;
}
