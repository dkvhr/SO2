// exercicio 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

void criar_recursivamente(const char *caminho) {
    char *copia = strdup(caminho);
    char *ptr = copia;
    char *caminho_parcial;

    while (*ptr) {
        // Pula o '/' inicial se existir
        if (*ptr == '/') {
            ptr++;
        }

        // Encontra o próximo separador
        caminho_parcial = strchr(ptr, '/');
        if (caminho_parcial) {
            *caminho_parcial = '\0';
        }

        if (mkdir(copia, 0755) != 0 && errno != EEXIST) {
            perror("Erro ao criar o diretório");
            free(copia);
            return;
        }

        if (caminho_parcial) {
            *caminho_parcial = '/';
            ptr = caminho_parcial + 1;
        } else {
            break;
        }
    }
    free(copia);
    printf("Diretórios criados com sucesso.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <caminho>\n", argv[0]);
        return 1;
    }
    criar_recursivamente(argv[1]);
    return 0;
}
