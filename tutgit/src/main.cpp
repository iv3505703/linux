#include <unistd.h>

int main(int argc, char** argv) {
    write(1, "opa\n",4);
    write(2, "error\n", 6);
    return 0;
}
