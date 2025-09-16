// exercicio 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <dir1> <dir2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (rmdir(argv[i]) == 0) {
            printf("Diretório '%s' removido com sucesso.\n", argv[i]);
        } else {
            perror("Erro ao remover o diretório");
        }
    }

    return 0;
}
