#include<stdio.h>
#include<sys/stat.h>

int main() {
	struct stat st, lst;

	stat("link2.txt", &st);
	lstat("link2.txt", &lst);

	// stat segue o link ate o arquivo real
	// lstat mostra sobre o proprio link
	printf("(stat) tamanho: %ld\n", st.st_size);
	printf("(lstat) tamanho: %ld\n", lst.st_size);

	return 0;

}
