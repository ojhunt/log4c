#include "log4c.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024

Log4CContextRef log4c_create_context(const Log4CAPIContext* context) {
    return (Log4CContextRef)context->log_function;
}

static Log4CLogFunction context_get_logger(Log4CContextRef context) {
    return (Log4CLogFunction)context;
}

void log4c_context(Log4CContextRef ctx, const char* msg, ...) {
    va_list format_args;
    va_start(format_args, msg);
    vlog4c_context(ctx, msg, format_args);
}

void vlog4c_context(Log4CContextRef ctx, const char* msg, va_list formatargs) {
    char buffer[BUFFER_SIZE];
    vsprintf(buffer, msg, formatargs);
    context_get_logger(ctx)(buffer);
}

static Log4CContextRef default_context;

void default_logger(const char* msg) {
    char command[BUFFER_SIZE];
    int command_length = strlen(msg) + 25; // length of the logger command
    snprintf(command, command_length, "logger -p user.notice \"%s\"", msg);
}

void log4c(const char* msg, ...) {
    if (default_context == NULL) {
        Log4CAPIContext default_definition = {
            .log_function = default_logger
        };
        default_context = log4c_create_context(&default_definition);
    }
    va_list format_args;
    va_start(format_args, msg);
    vlog4c_context(default_context, msg, format_args);
}
