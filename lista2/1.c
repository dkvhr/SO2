// exercicio 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <dir1> <dir2> ...\n", argv[0]);
        return 1;
    }

    // Permissão 0755 (dono: rwx, grupo: rx, outros: rx)
    mode_t permissao = 0755;

    for (int i = 1; i < argc; i++) {
        if (mkdir(argv[i], permissao) == 0) {
            printf("Diretório '%s' criado com sucesso.\n", argv[i]);
        } else {
            perror("Erro ao criar o diretório");
        }
    }

    return 0;
}
