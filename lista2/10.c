// exercicio 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char template[] = "/tmp/teste_XXXXXX";
    char *temp_dir = mkdtemp(template);
    if (!temp_dir) {
        perror("Erro ao criar diretório temporário");
        return 1;
    }
    printf("Diretório temporário criado: %s\n", temp_dir);

    // faz algumas operacoes
    char subpasta[256];
    snprintf(subpasta, 256, "%s/subpasta", temp_dir);
    if (mkdir(subpasta, 0755) == 0) {
        printf("Subpasta '%s' criada.\n", subpasta);
    }

    chdir(subpasta);
    printf("Navegou para: %s\n", subpasta);
    chdir("..");
    printf("Voltou para: %s\n", temp_dir);

    if (rmdir(subpasta) == 0 && rmdir(temp_dir) == 0) {
        printf("Diretórios removidos com sucesso.\n");
    } else {
        fprintf(stderr, "Erro ao remover os diretórios. Remova-os manualmente.\n");
        return 1;
    }

    return 0;
}
