#include <unistd.h>

int main(int argc, char** argv) {
    write(1, "opa\n",4);
    write(2, "error\n", 6);
    write(1, "dev2\n", 5);
    return 0;
}
