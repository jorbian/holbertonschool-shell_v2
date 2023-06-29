#include "hsh.h"

void throw_error(int line, int error_type, char *param)
{
    char types[4][32] = {
        "not found"
    };
    int type = error_type;

    fprintf(stderr, "./hsh: %d: %s: %s\n", line, param, types[type]);

    return;
}