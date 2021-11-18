#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include <pwd.h>
#include <stdint.h>

int main( int argc, char** argv) {
    int uid = getuid();
    printf("UID=%d", uid);

    uint16_t InitPid = getpid();

    pid_t result = fork();
    if(result == -1) {
        write(2, "Error\n", 7); return 1;
    }
    if(result == 0) printf("I am child PID=%d, PPID=%d\n", getpid(), getppid());
    else printf("I am parent, result=%d, PID=%d, PPID=%d\n", result, getpid(), getppid());
    
    return 0;
}

