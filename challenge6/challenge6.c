#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void print_stack(void *address, int range) {
    printf("\nStack Layout (around %p):\n", address);
    printf("Address\t\tValue\t\tASCII\n");
    printf("----------------------------------------\n");
    unsigned int *ptr = (unsigned int *)address;
    for (int i = -range/2; i < range/2; i++) {
        printf("%p\t0x%08x\t", ptr+i, *(ptr+i));        
        unsigned char *bytes = (unsigned char *)(ptr+i);
        for (int j = 0; j < 4; j++) {
            if (bytes[j] >= 32 && bytes[j] <= 126) {
                putchar(bytes[j]);
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    int secret = 0x1336;
    char buffer[32];
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    printf("=== 64-bit Buffer Overflow Challenge ===\n");
    printf("Objective: Overflow the buffer to change secret to 0x1337\n\n");
    
    printf("[Memory Addresses]\n");
    printf("buffer @ %p\n", buffer);
    printf("secret @ %p (value: 0x%x)\n", &secret, secret);
    
    print_stack(buffer, 25);
    
    printf("\nEnter your payload: ");
    fflush(stdout);
    
    read(0,buffer,48);
    
    printf("\n[After Overflow]\n");
    printf("secret = 0x%x\n", secret);
    print_stack(buffer, 25);

    if (secret == 0x1337) {
        printf("\nCongratulations! You have admin access now :) \n");
        system("/bin/sh");
    } else {
        printf("\nsecret is 0x%x, but needs to be 0x1337\n", secret);
    }

    return 0;
}

