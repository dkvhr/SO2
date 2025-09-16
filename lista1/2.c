#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	char read_str[100];
        if(argc < 2) {
                printf("Passe um parametro pela linha de comando!");
                exit(1);
        }
        int fd = open(argv[1], O_RDONLY);
        if(fd < 0) {
                exit(1);
        }
	int nread = read(fd, read_str, 100);
	write(1, read_str, nread);

	lseek(fd, 200, SEEK_SET);
	nread = read(fd, read_str, 50);
	write(1, read_str, nread);

	close(fd);
	return 0;
}
