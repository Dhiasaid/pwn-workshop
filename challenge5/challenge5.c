#include <stdio.h>
#include <stdlib.h>

void setup(){
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);
}

void gadgets(){
__asm__(
		"pop %rdi;\n"
		"ret;"
		"pop %rsi;\n"
		"ret;"
       );
}

void vuln(){
    char buf[8];
    printf("say something\n");
    gets(buf);
}
void win(int arg1,int arg2){
  printf("welcome to win function\n");
  printf("expecting 0xdeadbeef\n");
  printf("you entered 0x%016lx\n",arg1);
  printf("expecting 0xcafebabe\n");
  printf("you entered 0x%016lx",arg2);

  if(arg1 != 0xdeadbeef || arg2 != 0xcafebabe){
    printf("bye");
    exit(0);
  }
  else{
    printf("win\n");
    system("cat flag.txt");
  }
}


int main(){
  setup(); //don't mind this
  vuln();

}
