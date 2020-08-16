#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "errors.h"


unsigned long int str_to_ul(char* str) {
    char *endptr;
    unsigned long int ret;
    
    if (str[0] == '-') {
        handler_error(INVALID_INPUT, "Invalid number, not positive: %s", str);
    }
    ret = strtoul(str, &endptr, 10);
    if (endptr == str) {
        handler_error(INVALID_INPUT, "Invalid number: %s", str);
    } else if (*endptr) {
        handler_error(INVALID_INPUT, "Trailing characters after number: %s", str);
    } else if (errno == ERANGE) {
        handler_error(INVALID_INPUT, "Number out of range: %s", str);
    }
    return ret;
}