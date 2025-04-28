#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
    __asm__("and $0xFFFFFFFFFFFFFFF0, %rsp");  // Don't worry about this
    system("/bin/sh");
}

void vulnerable() {
    puts("What do you want to tell me: ");
    char buffer[16];
    gets(buffer);
}

void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
    setup(); // Don't mind this
    vulnerable();
    return 0;
}

