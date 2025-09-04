#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	if(argc < 2) {
		printf("Passe um parametro pela linha de comando!");
		exit(1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0) {
		exit(1);
	}
	struct stat st;
	fstat(fd, &st);

	if(S_ISREG(st.st_mode))
		printf("arquivo regular\n");
	else if(S_ISDIR(st.st_mode))
		printf("diretorio\n");
	else if(S_ISLNK(st.st_mode))
		printf("link simbolico\n");
	else
		printf("outro tipo\n");

	close(fd);
	return 0;
}
