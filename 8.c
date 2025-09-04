#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

void type(mode_t m) {
        if(S_ISREG(m))
                printf("arquivo regular\n");
        else if(S_ISDIR(m))
                printf("diretorio\n");
        else if(S_ISLNK(m))
                printf("link simbolico\n");
        else
                printf("outro tipo\n");
}

void print_perms(mode_t mode) {
        printf("%c%c%c", (mode & S_IRUSR) ? 'r' : '-',
                        (mode & S_IWUSR) ? 'w' : '-',
                        (mode & S_IXUSR) ? 'x' : '-');
        printf("%c%c%c", (mode & S_IRGRP) ? 'r' : '-',
                        (mode & S_IWGRP) ? 'w' : '-',
                        (mode & S_IXGRP) ? 'x' : '-');
        printf("%c%c%c\n",
                        (mode & S_IROTH) ? 'r' : '-',
                        (mode & S_IWOTH) ? 'w' : '-',
                        (mode & S_IXOTH) ? 'x' : '-');
}

int main(int argc, char **argv) {
        if(argc < 2) {
                printf("Passe parametros pela linha de comando!");
                exit(1);
        }

	for(int i=1; i < argc; i++) {
		struct stat st;
		if(lstat(argv[i], &st) == -1) {
			printf("erro no arquivo: %s\n", argv[i]);
			continue;
		}

		printf("%s: %ld bytes, ", argv[i], st.st_size);
		type(st.st_mode);
		print_perms(st.st_mode);
		printf("\n");
	}

	return 0;
}

