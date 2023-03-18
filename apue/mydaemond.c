#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void daemonize(void)
{
    pid_t pid, sid;
    /*
     * * 成为一个新会话的首进程，失去控制终端
     * */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid != 0) /* parent */
        exit(0);
    sid = setsid();
    /*
     * * 改变当前工作目录到/目录下.
     * */
    if (chdir("/home/ubuntu/") < 0) {
        perror("chdir error");
        exit(1);
    }
    /* 设置umask */
    umask(0022);  // 第一个0代表八进制，
                  // linux中默认创建一个普通文件的权限是644，掩码是022
    /*
     * * 重定向0，1，2文件描述符到 /dev/null，因为已经失去控制终端，再操作0，1，2没有意义.
     * */
    close(0);
    open("/dev/null", O_RDWR);
    dup2(0, STDOUT_FILENO);
    dup2(0, STDERR_FILENO);
}

int main(void)
{
    daemonize();
    while(1); /* 在此循环中可以实现守护进程的核心工作 */
}
