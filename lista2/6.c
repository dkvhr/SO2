// exercicio 6

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <caminho_destino>\n", argv[0]);
        return 1;
    }

    char original_dir[PATH_MAX];
    if (getcwd(original_dir, sizeof(original_dir)) == NULL) {
        perror("Erro ao obter o diretório atual");
        return 1;
    }
    printf("Diretório original: %s\n", original_dir);

    if (chdir(argv[1]) == 0) {
        char novo_dir[PATH_MAX];
        if (getcwd(novo_dir, sizeof(novo_dir)) != NULL) {
            printf("Diretório atual: %s\n", novo_dir);
        }
    } else {
        perror("Erro ao mudar para o diretório de destino");
        return 1;
    }

    if (chdir(original_dir) == 0) {
        printf("Voltando para o diretório original: %s\n", original_dir);
    } else {
        perror("Erro ao voltar para o diretório original");
        return 1;
    }

    return 0;
}
