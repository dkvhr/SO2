// exercicio 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void listar_diretorios(const char *caminho) {
    DIR *dir = opendir(caminho);
    if (!dir) {
        perror("Erro ao abrir o diretório");
        return;
    }

    printf("Entrando em: %s\n", caminho);
    if (chdir(caminho) != 0) {
        perror("Erro ao mudar de diretório");
        closedir(dir);
        return;
    }

    struct dirent *entrada;
    while ((entrada = readdir(dir)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        struct stat st;
        if (stat(entrada->d_name, &st) == 0 && S_ISDIR(st.st_mode)) {
            listar_diretorios(entrada->d_name);
        }
    }

    closedir(dir);
    if (chdir("..") != 0) {
        perror("Erro ao voltar");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <caminho>\n", argv[0]);
        return 1;
    }
    listar_diretorios(argv[1]);
    return 0;
}
