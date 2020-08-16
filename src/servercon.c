#include <stdio.h>

int servercon_loop();

int servercon(unsigned int lport) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Listening on port %d\n", lport);
    return servercon_loop();
}
int servercon_loop() {
    return 0;
}