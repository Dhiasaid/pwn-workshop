//gcc source.c -o vuln-64 -no-pie -fno-stack-protector
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln() {
    char buffer[64];

    puts("try to perform something you are not used to it");
    gets(buffer);
}

int main() {
    vuln();
}
