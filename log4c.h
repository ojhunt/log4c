#ifndef __LOG4C__
#define __LOG4C__

#include <stdarg.h>

#ifdef __cplusplus__
extern "C" {
#endif

void log4c(const char* msg, ...) __attribute__((format(printf, 1, 2)));

// Sigh, need to add some os_log style cruft to make testing possible
typedef void (*Log4CLogFunction)(const char*);

typedef struct {
    Log4CLogFunction log_function;
} Log4CAPIContext;

typedef const struct Log4CContext* Log4CContextRef;
Log4CContextRef log4c_create_context(const Log4CAPIContext*);

void log4c_context(Log4CContextRef ctx, const char* msg, ...) __attribute__((format(printf, 2, 3)));
void vlog4c_context(Log4CContextRef ctx, const char* msg, va_list args);
#ifdef __cplusplus__
}
#endif

#endif // __LOG4C__
