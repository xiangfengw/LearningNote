#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid ;

    pid = fork();

    if (pid > 0) {
        sleep(3);

    } else if (pid == 0) {
        //ls -l
        char *argv[] = {"ls", "-l", "-a", NULL};

        execvp("ls", argv);  // ./a.out  aaa  bbb  ccc 
        perror("execlp error");
        exit(1);
    }

    return 0;
}
