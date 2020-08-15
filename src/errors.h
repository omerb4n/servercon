typedef enum Error {
    UNKNOWN_ERROR = 0,
    INVALID_INPUT
} Error;

void handler_error(Error err, const char* format, ...);
