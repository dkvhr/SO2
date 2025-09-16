// exercicio 9

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <diretorio>\n", argv[0]);
        return 1;
    }

    const char *diretorio = argv[1];
    // Permissões iniciais (mas as umask podem restringir)
    mode_t permissao_mkdir = 0777;
    mode_t permissao_final = 0750;

    if (mkdir(diretorio, permissao_mkdir) == 0) {
        printf("Diretório '%s' criado.\n", diretorio);
        if (chmod(diretorio, permissao_final) == 0) {
            printf("Permissões de '%s' alteradas para rwxr-x---.\n", diretorio);
        } else {
            perror("Erro ao alterar as permissões");
            return 1;
        }
    } else {
        perror("Erro ao criar o diretório");
        return 1;
    }

    return 0;
}
