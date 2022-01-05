#include "log4c.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void log4c(const char* msg, ...) {
    char buffer[1024];
    va_list formatargs;
    va_start(formatargs, msg);

    // FIXME: need to work out the size of the format string
    int message_length = vsprintf(buffer, msg, formatargs);

    char command[1024];
    int command_length = message_length + 25; // length of the logger command
    snprintf(command, command_length, "logger -p user.notice \"%s\"", buffer);
    system(command);
}
