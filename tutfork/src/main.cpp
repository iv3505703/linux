#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include <pwd.h>

int main( int argc, char** argv) {
    int uid = getuid();
    printf("UID=%d", uid);
}

