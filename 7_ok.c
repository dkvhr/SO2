#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv) {
        if(argc < 2) {
                printf("Passe um parametro pela linha de comando!");
                exit(1);
        }
        int fd = open(argv[1], O_RDWR);
        if(fd < 0) {
                exit(1);
        }

	off_t pos = 20;
	if(ftruncate(fd, pos) == -1) {
		fprintf(stderr, "erro no ftruncate\n");
		close(fd);
		exit(1);
	}
	if(lseek(fd, pos, SEEK_SET) == -1) {
		fprintf(stderr, "erro no lseek");
		close(fd);
		exit(1);
	}
	if(write(fd, "FIM\n", 4) != 4) {
		fprintf(stderr, "erro no write");
		close(fd);
		exit(1);
	}

	close(fd);
	return 0;
}
