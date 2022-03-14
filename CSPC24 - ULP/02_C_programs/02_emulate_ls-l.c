#include <unistd.h>

void main() {
    execlp("ls", "ls", "-l", NULL);
}