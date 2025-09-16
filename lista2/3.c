// exercicio 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <caminho>\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Diretório atual mudado para: %s\n", cwd);
        } else {
            perror("Erro ao obter o diretório atual");
            return 1;
        }
    } else {
        perror("Erro ao mudar de diretório");
        return 1;
    }

    return 0;
}
