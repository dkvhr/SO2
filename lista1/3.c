#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>

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
                printf("Passe um parametro pela linha de comando!");
                exit(1);
        }
	struct stat st;
	stat(argv[1], &st);
	printf("tamanho: %ld\n", st.st_size);
	printf("numero de links: %ld\n", st.st_nlink);
	printf("uid do dono: %d\n", st.st_uid);
	printf("ultima modificacao: %s\n", ctime(&st.st_mtime));
	print_perms(st.st_mode);

	return 0;
}

