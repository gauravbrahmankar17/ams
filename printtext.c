#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
typedef struct entry {
	char * username;
	char * password;
} entry;
int main(int argc, char **argv) {
        entry name,hey;
	int fp;
	name.username = "gaurav";
	name.password = "gau";
	fp = open("abc.txt",O_RDONLY | O_CREAT);
	write(fp, name.username , sizeof(name.username));
	read(fp , (hey.username), sizeof(hey.username));
	printf("%s ", hey.username);
	
	return 0;
}


