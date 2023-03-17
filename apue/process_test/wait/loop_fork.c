#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int n = 5, i;				//默认创建5个子进程
    pid_t p, q;

	if(argc == 2){	
		n = atoi(argv[1]);
	}

	for(i = 0; i < n; i++)	 {//出口1,父进程专用出口
        p = fork();
		if(p == 0) {
			break;			//出口2,子进程出口,i不自增
        } else if (i == 3){
            q = p;
        }
    }
	pid_t wpid;
	if(n == i){
		sleep(n);
		printf("I am parent, pid = %d\n", getpid());
        do{
			wpid = waitpid(q, NULL, WNOHANG);
			sleep(1);
		} while(wpid == 0);
        // pid_t pid = wait(NULL);
        printf("wait finish, child pid = %d\n", wpid);
		while(1);
	} else {
		sleep(i);
		printf("I'm %dth child, pid = %d, gpid=%d\n", 
				i+1, getpid(), getgid());
	}

	return 0;
}
