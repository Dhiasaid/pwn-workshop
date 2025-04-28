#include <stdio.h>

void win(long first, long second)
{
    if (first == 0xdeadbeefdeadbeef && second == 0xc0debabec0debabe){
        printf("This function is TOP SECRET! How did you get in here?! :O\n");
	system("/bin/sh");
    }else{
        printf("Unauthorised access to secret function detected, authorities have been alerted!!\n");
    }
}

void register_name()
{
    char buffer[16];

    printf("ech esmek:\n");
    scanf("%s", buffer);
    printf("asslema, %s\n", buffer);    
}

int main()
{
    register_name();

    return 0;
}
