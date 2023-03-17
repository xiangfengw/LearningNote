#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("xxxxxxxx\n");

    pid = fork();
    if(pid == -1) {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0) {
        printf("child, pid = %u, ppid = %u\n", getpid(), getppid());
    } else {
        printf("parent, pid = %u, ppid = %u\n", getpid(), getppid());
        sleep(1);
    }

    printf("yyyyyyyyy\n");

    return 0;
}