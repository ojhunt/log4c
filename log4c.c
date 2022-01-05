#include "log4c.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void log4c(const char* msg, ...) {
    char buffer[1024];
    va_list formatargs;
    va_start(formatargs, msg);
    vsprintf(buffer, msg, formatargs);
    char command[1024];
    sprintf(command, "logger -p user.notice \"%s\"", buffer);
    system(command);
}
