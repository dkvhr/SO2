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

	if(lseek(fd, 20, SEEK_SET) == (off_t)-1) {
		fprintf(stderr, "erro no lseek");
		close(fd);
		exit(1);
	}

	ssize_t w_bytes = write(fd, "FIM\n", 4);
	if(w_bytes == -1) {
		fprintf(stderr, "erro no write");
		close(fd);
		exit(1);
	}

	close(fd);
	return 0;
}
