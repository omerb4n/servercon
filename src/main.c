#include <stdio.h>
#include "utils.h"
#include "servercon.h"
#define DEFAULT_PORT 8000

int main(int argc, char** argv) {
    unsigned long int lport = DEFAULT_PORT;
    if (argc >= 2) {
        lport = str_to_ul(argv[1]);
    }
    servercon(lport);
}