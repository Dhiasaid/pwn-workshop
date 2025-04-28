#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void vuln() {
    char buffer[100];
    char input[100];
    int fd;

    fd=open("flag.txt", 0);
    if (fd < 0) {
        perror("open");
        return;
    }

    read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    buffer[sizeof(buffer) - 1] = '\0'; 

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    printf(input);

}

int main() {
    printf("Welcome to CTF Format String!\n");
    vuln();
    return 0;
}


