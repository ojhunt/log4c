#ifndef __LOG4C__
#define __LOG4C__

void log4c(const char* msg, ...) __attribute__((format(printf, 1, 2)));

#endif // __LOG4C__
