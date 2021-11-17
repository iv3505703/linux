#include <cstdio>
#include <unistd.h>

int main(int argc, char** argv) {
    write(2, "opa",3);
    return 0;
}
