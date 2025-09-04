#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
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
	off_t size = lseek(fd, 0, SEEK_END);
	printf("%ld\n", size);
	close(fd);
	return 0;
}
