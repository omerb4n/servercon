#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include "errors.h"

/* Edit typedef enum Error in error.h accordingly */
static const char* ERRORS_MESSAGES[] = 
{
    "Unknown error",
    "Invalid input",
    "Socket error"
};

static const char* const error_str(Error err) {
    const char* err_str = ERRORS_MESSAGES[UNKNOWN_ERROR];

    // Ensure error codes are within the valid array index range
    if (err < sizeof(ERRORS_MESSAGES))
    {
        err_str = ERRORS_MESSAGES[err];
    }
    return err_str;
}

void handler_error(Error err, const char* format, ...) {
    fprintf(stderr, "%d: %s (", err, error_str(err));
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    fprintf(stderr, ")");
    if (errno) {
        fprintf(stderr, " (%d: %s)", errno, strerror(errno));
    }
    fprintf(stderr, "\n");
    exit(errno ? errno: -1);
}
