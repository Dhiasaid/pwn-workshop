//gcc source.c -o vuln-64 -no-pie -fno-stack-protector
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln() {
    char buffer[64];
    int secret=0;
    puts("try to perform something you are not used to it");
    gets(buffer);
    if (secret=0xdeadbeef){
	    printf("good job you did it ");
            system("/bin/sh");
    }
}

int main() {
    vuln();
}
