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
	lseek(fd, 0, SEEK_SET);

	int count = 0;
	unsigned char c;
	for(off_t i = 0; i<size; i++) {
		lseek(fd, i, SEEK_SET);
		if(read(fd, &c, 1) == 1 && c == '\0')
			count++;
	}

	printf("bytes nulos: %d\n", count);
	close(fd);
	return 0;
}
