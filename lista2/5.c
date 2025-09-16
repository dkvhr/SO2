// exercicio 5

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <diretorio>\n", argv[0]);
        return 1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return 1;
    }

    int count = 0;
    while (readdir(dir) != NULL) {
        count++;
    }
    closedir(dir);

    if (count > 2) {
        printf("Erro: O diretório '%s' não está vazio e não pode ser removido.\n", argv[1]);
        return 1;
    }

    if (rmdir(argv[1]) == 0) {
        printf("Diretório '%s' removido com sucesso.\n", argv[1]);
    } else {
        perror("Erro ao remover o diretório");
        return 1;
    }

    return 0;
}
