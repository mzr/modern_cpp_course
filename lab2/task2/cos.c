#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int a = open("main.cpp", O_RDWR);
    int b = open("main.cpp", O_RDWR);

    lseek(a, 10, SEEK_SET);

    printf("%d %d\n", a, b);

    char c;

    pid_t pid = getpid();
    printf("pid: %d\n", pid);

    scanf("%c", &c);


    // kursor nie jest taki sam dla a i b.


    return 0;
}


