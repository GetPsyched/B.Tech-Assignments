#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main() {
    int fd[2];
    char buf1[20] = "Hello, World";
    char buf2[12];

    int pid = getpid();

    printf("pid --> %d\n",pid);

    printf("%d\n",S_IWUSR);

    fd[0] = open("sample.txt", O_RDWR | O_CREAT,S_IRUSR | S_IWUSR);
    fd[1] = open("sample.txt", O_RDWR);

    printf("%d %d\n",fd[0],fd[1]);

    write(fd[0], buf1, strlen(buf1));
    write(1, buf2, read(fd[1], buf2, 12));
    printf("\n");

    close(fd[0]);
    close(fd[1]);
}
